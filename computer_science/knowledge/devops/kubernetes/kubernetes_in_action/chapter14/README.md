# Pod's computational resources

When creating a pod, you can specify the amount of CPU and memory that a
container need(requests) and a hard limit on what it may consume(limits). The
pod's resource requests and limits are the sum of the requests and limits of
all its containers.

```yaml
resources:
  requests:
    cpu: 200mi
    memory: 10Mi
```

In the pod manifest, your single container requires one-fifth of a CPU
core(200 milicores) to run properly. Five such pods/containers can run
sufficiently fast on a single CPU core.
