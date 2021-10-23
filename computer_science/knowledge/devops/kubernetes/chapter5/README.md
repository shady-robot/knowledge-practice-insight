# Pods

In real-world deployments of containerized application, you will often want to
colocate multiple applications into a single atomic unit, scheduled onto single
machine.

## Pods in kubernetes

A pod represents a collection of application containers and volumes running in
the same execution environment. Pods, not containers, are the smallest
deployable artifact in a Kubernetes cluster. This means all of the containers
in a Pod always land on the same machine.

Each container within a Pod runs in its own `cgroup`, but they share a number
of Linux namespaces.

Applications running in the same Pod shared the same IP address and port space,
(network namespace), have the same hostname(UTS namespace), and can communicate
using native interprocess communication channels over System V IPC or POSIX
message queue(IPC namespace).

### Thinking with pods

""Will these containers work correctly if they land on different machines. If
the answer is "no", a Pod is the correct grouping for the containers.

### The pod manifest

Pods are describe in a Pod manifest. The Pod manifest is just a text-file
representation of the Kubernetes API object. The Kubernetes API server accepts
and processes Pod manifests before storing them in persistent storage(etcd).
he scheduler also use the Kubernetes API to find Pods that haven't been
scheduled to a node. The scheduler then places the Pods onto nodes depending on
the resources and other constrains expressed in the Pod manifests.

### Interact with pod

Pod manifests include a couple of key fields and attributes: mainly a metadata
section for describing the Pod and its labels, a `spec` section for describing
volumes, and a list of containers that will run in the Pod.

```shell
kubectl run kuard --image=gcr.io/kuar-demo/kuard-amd64:1
kubectl get pods
kubectl delete deployment/kuard
kubectl apply -f kuard_pod.yaml
kubectl get pods
kubectl describe pods kuard
kubectl delete pods kuard
kubectl port-forward kuard 8080:8080
kubectl logs kuard
kubectl exec kuard date
```

refer to [kuard_pod.yaml](./kuard_pod.yaml)

Pod manifests can be written using YAML or JSON, but YAML is generally preferred
because it is slightly more human-editable and has the ability to add comments.

The Pod manifest will be submitted to the Kubernetes API server. The Kubernetes
system will then schedule that Pod to run on a healthy node in the cluster,
where it will be monitored by the kubelet daemon process.

## Health check

When you run your application as a container in Kubernetes, it is automatically
kept alive for you using a process health check. This health check simply
ensures that the main process of your application is always running. If it
isn't, Kubernetes restarts it.

To address this, Kubernetes introduced health check for application liveness.
Liveness health checks run application-specific logic to verify that the
application is not just still running, but is functioning properly. Since these
liveness health checks are application-specific, you have to define them in your
Pod manifest.

### Liveness probe

The following Pod manifest uses an httpGet probe to perform an HTTP GET request
against the /healthy endpoint on port 8080 of the kuard container.

```yaml
livenessProbe:
  httpGet:
    path: /healthy
    port: 8080
    initialDelaySeconds: 5
    timeoutSeconds: 1
    periodSeconds: 10
    failureThreshold: 3
```

### Readliness probe

Kubernetes makes a distinction between liveness and readiness. Liveness
determines if an application is running properly. Containers that fail liveness
checks are restarted. Readiness describes when a container is ready to serve
user requests. Containers that fail readiness checks are removed from service
load balancers.

## Resource management

With scheduling systems like Kubernetes about managing resource packing, you can
drive your utilization to greater than 50%/ To achieve this, you have to tell
Kubernetes about the resources your application requires, so that Kubernetes can
find the optimal packaging of containers onto purchases machines.

Kubernetes allows users to specify two different resource metrics.

* resource requests: the minimum amount of a resource required to run the
  application.
* resource limit: the maximum amount of a resource that an application can
  consume.

### Resource requests

With Kubernetes, a Pod requests the resources required to run its containers.
Kubernetes guarantees that these resources are available to the Pod.

```yaml
resources:
  cpu: "500m"
  memory: "128Mi"
```

Resources are requested per container, not per Pod. The total resources
requested by the Pod is the sum of all resources requested by all containers in
the Pod. CPU requests are implemented using the cpu-shares functionality in the
Linux kernel.

When your establish limits on a container, the kernel is configured to ensure
that consumption cannot exceed these limits. A container with a CPU limit of
0.5 cores will only ever get 0.5 core, even if the CPU is otherwise idle.

## Persisting data with volumes

When a Pod is deleted or a container restarts, any and all data in the
container's filesystem is also deleted.

### Using volumes with Pods

To add a volume to a Pod manifest, there are two new stanzas to add to our
configuration.

* The `sepc.volumes` section: This array defines all of the volumes that may be
  accessed by containers in the Pod manifest.
* The `volumeMounts` section: This array defines the volumes that are mounted
  into a particular, and the path where each volume should be mounted.

```yaml
spec:
  volumes:
    - name: "kuard-data"
      hostPath:
        path: "/var/lib/kuard"
containers:
    - image: XXX
      name: kuard
      volumeMounts:
        - mountPath: "/data"
          name: "kuard-data"
```

### Different ways of using volumes with pods

* communication/synchronization
* cache
* persistent data

### Persisting data using remote disks

When using network-based storage, Kubernetes automatically mounts and unmounts
the appropriate storage whenever a Pod using that volume is scheduled onto a
particular machine.
