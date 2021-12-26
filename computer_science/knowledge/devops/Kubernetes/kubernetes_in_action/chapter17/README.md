# Best practice for developing apps

![Kubernetes all in one](./images/kubernetes_all_in_one.png)

A typical application manifest contains one or more Deployment and/or
StatefulSet objects. Those include a pod template containing one or more
container, with a liveness probe for each of them and a readiness probe for the
services the container provides. Pods that provide services to others are
exposed through one or more Services. When they need to be reachable from
outside the cluster, the Services are either configured to be LoadBalancer or
NodePort-type Services, or exposed through an Ingress resource.

The pod templates usually reference two types of Secrets - those for pulling
container images from private image registries and those used directly by the
process running inside from private image registries and those used directly by
the process running inside the pods. The Secrets themselves are usually not part
of the application manifest, because they aren't configured by the application
developers but by the operations team. Secrets are usually assigned to
ServiceAccounts, which are assigned to individual pods.

The application also contains one or more ConfigMaps, which are either used to
initialize environment variables or mounted as a ConfigMap volume in the pod.
Certain pods use additional volumes, such as an emptyDir or a gitRepo volume,
whereas pods requiring persistent storage use persistentVolumeClaim volumes. The
PersistentVolumeClaims are also part of the application manifest, whereas
StorageClasses referenced by them are created by system administrator upfront.

## Starting pods in a specific order

You can prevent a pod's main container from starting until a precondition is
met. This is done by including an init container in the pod.

### Init containers

Init containers are used to initialize the pod - this often means writing data
to the pod's volumes, which are then mounted into the pod's main container(s).
A pod may have any number of init containers. They're executed sequentially and
only after the last one completes are the pod's main containers started. An init
container could wait for a service required bu the pod's main container to be up
and ready.

#### Inter-pod dependencies

The application needs to handle internally the possibility that its dependencies
aren't ready. And don't forget readiness probes. If an app can't do its job
because one of its dependencies is missing, it should signal that through its
readiness probe, so Kubernetes knows it, too, isn't ready.

## Lifecycle hooks

* Post-start hooks
* Pre-stop hooks

These lifecycle hooks are specified per container, unlike init container, which
apply to the whole pod. Lifecycle hooks are similar to liveness and readiness
probes in that they can either:

* Execute a command inside the container
* Perform an HTTP GET request against a URL

A post-start hook is executed immediately after the container's main process is
started. You use it to perform additional operations when the application
starts.  Post-start hooks allows you to run additional commands without having
to touch the app. These may signal to an external listener that the app is
starting, or they may initialize the application so it can start doing its job.
The hook is run in parallel with the main process.

But even though the hook runs asynchronously, it does affect the container in
two ways. Until the hook completes, the container will stay in the Waiting state
with the reason `ContainerCreating`. Because of this, the pod's status will be
`Pending` instead of `Running`. If the hook fails to run or returns a non-zero
exit code, the main container will be killed.

```yaml
spec:
  containers:
  - image: luksa/kubia
    name: kubia
    lifecycle:
      postStart:
        exec:
          command:
          - sh
          - -c
```

The standard and error outputs of command-based post-start hooks aren't logged
anywhere, so you may want to have the process the hook invokes log to a file in
the container's filesystem, which will allow you to examine the contents of log
file.

### Pre-stop hook

A pre-stop hook is executed immediately before a container is terminated.When a
container needs to be terminated, the Kubelet will run the pre-stop hook, if
configured, and only then send a SIGTERM to the process. A pre-stop hook can be
used to initiate a graceful shutdown of the container, if it doesn't shut down
gracefully upon receipt of a SIGTERM signal.

```yaml
liftcycle:
  preStop:
    httpGet:
      port: 8080
      path: shutdown
```

## Understand pod shutdown

A pod's shut-down is triggered by the deletion of the Pod object through the API
server. Upon receiving an HTTP DELETE request, the API server doesn't delete the
object yet, but only sets a deletetionTimestamp field in it. Pods that have the
deletionTimeStamp field set are terminating.

Once the kubelet notices the pod needs to be terminated, it starts terminating
each of the pod's cotnainers. It gives each container time to shut down
gracefully, but the time is limited. That time is called the termination grace
period and is configurable per pod.

1. Run the pre-stop hook, if one is configured, and wait for it to finish.
2. Send the SIGTERM signal to the main process of the container
3. Wait until the container shuts down cleanly or until the termination grace
   period runs out.
4. Forcibly kill the process with SIGKILL, if it hasn't terminated gracefully
   yet.

```shell
kubectl delete pod mypod --grace-period=5
kubectl delete pod mypod--grace-period=0 --force
```

### Implementing the proper shutdown handler in your application

Replace critical shut-down procedures with dedicated shut-down procedure pods.
The proper way to handle this problem is by having a dedicated, constantly
running pod that keeps checking for the existence of orphaned data. When this
pod finds the orphaned data, it can migrate it to the remaining pods. Rather
than a constantly running pod, you can also use a CronJob resource and run the
pod periodically.

## Ensuring all client requests are handled properly

### Preventing broken client connections when a pod is starting up

If you don't specify a readiness probe, the pod is always considered ready. It
will start receiving requests almost immediately - as soon as the first
kube-proxy updates the iptables rules on its node and the first client pod tries
to connect to the service.
All you need to do is make sure that your readiness probe returns success only
when your app is ready to properly handle incoming requests.

### Preventing broken connection during pod shut-down

The end result is that the pod may still receive client requests after it was
sent the termination signal. It's clear the pod needs to keep accepting
connections even after it receives the termination signal up until all the
kube-proxies have finished updating the iptables rules.

To recap - properly shutting down an application includes these steps:

1. Wait for a few seconds, then stop accepting new connections.
2. Close all keep-alive connections not in the middle of a request.
3. Wait for all active requests to finish.
4. Then shut down completely.

## Making your apps easy to run and manage in Kubernetes

### Manageable container images

Deploying new pods and scaling them should be fast. This demands having small
images without unnecessary cruft. Application built with go don't need to
include anything else apart from the app's single binary executable file.

### Properly tagging your images and using imagePullPolicy wisely

Keep in mind that if you use mutable tags, you'll need to set the
imagePullPolicy field in the pod spec to Always. If the image pull policy is set
to Always, the container runtime will contact the image registry every time a
new pod is deployed. This slows down pod startup a bit, because the node needs
to check if the image has been modified. Worse yet, this policy prevents the pod
from starting up when the registry cannot be contacted.

### Using multi-dimensional instead of single-dimensional labels

Don't forget to label all your resources, not only Pods. Make sure you add
multiple labels to each resource, so they can be selected across each individual
dimension.

* The name of the application the resource belongs to.
* Application tier(front-end, back-end, and so on).
* Environment(development, AQ, staging, production, and so on)
* Type of release(stable, canary, green or blue for green/blue deployments,
  and so on)
* Tenant(if you're running separate pods for each tenant instead os using
  namespaces)
* Shared for shared systems.

#### Describe each resource through annotations

To add additional information to your resources use annotations. At the least,
resources should contain an annotation describing the resource and an annotation
with contact information of the person responsible for it.

#### Providing information on why the process terminated

Kubernetes feature that make it possible to show the reason why a container
terminated in the pod's status. You do this by having the process write a
termination message to a specific file in the container's filesystem. The
contents of this file are read by the Kubelet when the container terminates and
are shown in the output of `kubectl describe pod`. If an application uses this
mechanism, an operator can quickly see why the app terminated without even
having to look at the container logs.

The default file the process needs to write the message is
`/dev/termination-log`, but it can be changed by setting the
`terminationMessagePath` field in the container definition in the pod spec.

#### Handling application logs

While we're on the subject of application logging, let's reiterate that apps
should write to the standard output instead if files. This makes it easy to view
logs with the kubectl logs command.
