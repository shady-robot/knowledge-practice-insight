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

## Resource Limit

To limit the amount of memory and CPU a container can consume.

```yaml
resources:
  limits:
    cpu: 1
    memory: 20Mi
```

The process or processes running inside the container will not be allowed to
consume more than 1 CPU core and 20 mebibytes memory.[Because you haven't
specified any resource requests, they'll be set to the same values as the
resource limits.]

Unlike resource requests, resource limits aren't constrained by the node's
allocatable resource amount. The sum of all limits of all the pods on a node is
allowed to exceed 100% of the node's capacity. Restated, resource limits can be
overcommitted. This has an important consequence - when 100% of the node's
resources are used up, certain containers will need to be killed.

### Exceeding the limits

CPU is a compressible resource, and it's only natural for a process to want to
consume all the CPU time when not waiting for an I/O operation. A process' CPU
usage is throttled, so when a CPU limit is set for a container, the process
isn't given more CPU time than the configured limit.

When a process tries to allocate memory over its limit, the process is killed
(it’s said the container is OOMKilled, where OOM stands for Out Of Memory). If
the pod’s restart policy is set to Always or OnFailure, the process is restarted
immediately, so you may not even notice it getting killed. But if it keeps going
over the memory limit and getting killed, Kubernetes will begin restart- ing it
with increasing delays between restarts.

Even though you set a limit on how much memory is available to a container, the
container will not be aware of this limit. Setting a CPU limit to one core
doesn't magically only expose only one CPU core to the container. All the CPU
limit does is constrain the amount of CPU time the container can use.

You may want to use the Downward API to pass the CPU limit to the container and
use it instead of relying on the number of CPUs your app can see on the system.
You can also tap into the cgroups system directly to get the configured CPU
limit by reading the following files:

```console
/sys/fs/cgroup/cpu/cpu.cfs_quota_us
/sys/fs/cgroup/cpu/cpu.cfs_period_us
```

## Pod QoS classes

Kubernetes determine pod's priority by categorizing pods into three Quality of
Service (QoS) classes.
