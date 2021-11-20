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
