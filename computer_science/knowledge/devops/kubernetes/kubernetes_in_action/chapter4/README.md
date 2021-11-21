# Replication & controllers

## Liveness probes

Kubernetes can check if a container is still alive through liveness probes. You
can specify a liveness probe for each container in the pod's specification.
Kubernetes will periodically execute the probe and restart the container if the
probe fails.

Kubernetes can probe a container using one of the three mechanisms:

* An HTTP GET probe performs an HTTP GET on the container's IP address, a port
  and a path you specify.
* A TCP Socket probe tries to open a TCP connection to the specified port of the
  container.
* An Exec probe executes an arbitrary command inside the container and checks
  the command's exit status code.

### Crashed container logs

When you want to figure out why the previous container terminated, you'll want
to see those logs instead of the current container's logs. This can be done by
using the `--previous` options.

`$ kubectl logs mypod --previous`

### Creating effective liveness probes

Always remember to set an initial delay to account for your app's startup time.
For pods running in production, you should always define a liveness probe.
Without one, Kubernetes has no way knowing whether your app is still alve or
not. As long as the process is still running, Kubernetes will consider the
container to be healthy.

For better liveness check, you'd configured the probe to perform requests on a
specific URL path,(/health, for example) and have the app perform an itnernal
status check of the vital components running inside the app to ensure none of
them has died or is unresponsive. Be sure to check only the internals of the
app and nothing influenced by an external factor.

```shell
livenessProbe:
    httpGet:
      path: /
      port: 8080
    initialDelaySeconds: 15
```

Kubernetes keeps your containers running by restarting them if they crash or if
their liveness probes fail. This job is performed by the Kubelet on the node
hosting the pod -- Kubernetes Control Plane components running on the master
have no part in this process.

## ReplicationControllers

A ReplicationController is a Kubernetes resource that ensures its pods are
always kept running. A ReplicationController constantly monitors the list of
running pods and make sure the actual number of pods of a "type" always matches
the desired number. ReplicationController don't operate on pod types, but on
sets of pods that match a certain label selector.

### Controller's reconciliation loop

A ReplicationController's job is to make sure that an exact number of pods
always matches its label selector.

A ReplicationController has three essential parts:

* A label selector, which determines what pods are in the
  ReplicationController's scope.
* A replica count, which specific the desired number of pods that should be
  running
* A pod template, which is used when creating new pod replicas.

A pod instance is never relocated to another node. Instead, the
ReplicationController creates a completely new pod instance that has no relation
to the instance it's replacing.

While a ReplicationController is immediately notified about a pod being deleted
(The API server allows clients to watch for changes to resources and resource
lists), that's now what cause it to create a replacement pod. The notification
triggers the controller to check the actual number of pods and take appropriate
action.

By changing pod's labels, it can be removed from or added to the scope of a
ReplicationController. It can even be moved from one ReplicationController to
another.

```shell
kubectl edit rc kubia
kubectl scale rc kubia --replicas=3
# Keep pods running by passing the --cascade=false option to the command.
kubectl delete rc kubia --cascade=false
```

## ReplicaSet

A ReplicaSet behave exactly like a ReplicationController, but it has more
expressive pod selectors.

```yaml
selector:
  matchExpressions:
    - key: app
      operator: In
      values:
        - kubia
```

You can add additional expressions to the selector. Each expression must contain
a key, an operator, and possibly a list of values.

* In - Label's value must match one of the specific values.
* Not In - Label's value must not match any of the specified values.
* Exists - Pod must include a label with the specific key.(The value isn't
  important)
* DoesNotExist - Pod must not include a label with the specified key.
