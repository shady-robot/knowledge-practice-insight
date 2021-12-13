# Pods

A Pod is a co-located group of containers and represents the basic building
block in Kubernetes. Because you're not supposed to group multiple processes
into a single container, it's obvious you need another higher-level construct
that will allow you to bind containers together and manage them as a single
unit.

A Pod of containers allows you to run closely related processes together and
provide them with the same environment as if they were all running in a single
container, while keeping them somewhat isolated.

All containers of a pod run under the same Network and UTS namespaces, they all
share the same hostname and network interfaces.

## The flat inter-pod network

All pods in a Kubernetes cluster reside in a single flat, shared,
network-address space, which means every pod can access every other pod at the
other pod's IP address.[Like computer on a LAN, each pod gets its own IP address
and is accessible from all other pods through this network established
specifically for pods.]

## Organizing containers across pods

Instead of stuffing everything into a single pod, you should organize apps into
multiple pods, where each one contains only tightly related components or
processes.

* Improving the utilization of your infrastructure
* Enabling individual scaling

The main reason to put multiple containers into a single pod is when the
application consists of one main process and one or more complementary
processes. Basically, you should always gravitate toward running containers in
separate pods, unless a specific reason requires them to be part of the same
pod.

## Pod definitions

* Metadata includes the name, namespace, labels and other information about the
  pod.
* Spec containers the actual description of the pod's contents, such as pod's
  containers, volumes, and other data.
* Status contains the current information about the running pod, such as what
  condition the pod is in, the description and status of each container, and the
  pod's internal IP and other basic info.

```shell
$ kubectl logs kubia-manual -c kubia
# Forward a local network port to a port in the Pod
$ kubectl port-forward kubia-manual 8888:8080
```

Container logs are automatically rotated daily and every time the log file
reaches 10 MB in size. The `kubectl logs` command only shows the log entries
from the last rotation.

## Labels

Organizing pods and all other Kubernetes objects is done through labels.

A label is an arbitrary key-value pair you attach to a resource, which is then
utilized when selecting resources using label selectors(resources are filtered
based on whether they include the label specified in the selector.)

```shell
$ kubectl get pod --show-labels

# -L display labels value in column
$ kubectl get pod -L creation_method,env

# modify labels of existing pods
$ kubectl label pod kubia-manual-v2 env=debug --overwrite

# delete labels of existing pods
$ kubectl label pod kubia-manual-v2 env-

$ kubectl get pod  -l creation_method=manual
# List all pods that include the env label, whatever its value is.
$ kubectl get pod  -l env

# Using the nodeSelector in spec
$ kubectl label node gke-kubia-85f6-node-0rrx gpu=true
```

Always think about logical groups of nodes that satisfy certain criteria
specified through label selectors.

## Annotating pods

Annotations can hold much larger pieces of information and are primarily meant
to be used by tools. Certain annotations are automatically added to objects by
Kubernetes, but others are added by users manually.

```shell
kubectl annotate pod kubia-manual mycompany.com/someannotation="foo bar"
kubectl describe pod kubia-manual
```

## Namespaces

Kubernetes namespace provide a scope for objects names.Using multiple namespaces
allows you to split complex systems with numerous components into smaller
distinct groups.

Namespaces enable you to separate resources that don't belong together into
non-overlapping groups. Besides isolating resources, namespaces are also used
for allowing only certain users access to particular resources and even for
limiting the amount of computational resources available to individual users.
