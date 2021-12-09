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

## Scheduler

When scheduling a pod, the Scheduler will only consider nodes with enough
unallocated resources to meet the pod's resource requirement. The Scheduler
first filter the list of nodes to exclude those that the pod can't fit on and
then priorities the remaining nodes per the configured prioritization functions.

* LeastRequestedPriority: prefer nodes with fewer requested resources(with
  greater amount of unallocated resources)
* MostRequestedPriority: prefer nodes that have the most requested resource.

The Scheduler needs to know how much APU and memory each node has, the Kubelet
reports this data to the API server, making it available through the Node
resource. The Scheduler bases its decisions only on the allocatable resource
amounts.

```shell
kubectl run requests-pod-4 --image=busybox --restart Never --requests='cpu=1,memory=20Mi' -- dd if=/dev/zero of=/dev/null
```

The CPU requests don't only affect scheduling - they also determine how the
remaining CPU time is distributed between pods.

### Defining and requesting custom resources

Kubernetes also allows you to add your own custom resources to a node and
request them in the pod's resource requests.

An example of custom resource could be the number of GPU unit available on the
nodes. Pods requiring the use of a GPU specify that in their requests. The
Scheduler then makes sure the pod is only scheduled to nodes with at least one
CPU still unallocated.
