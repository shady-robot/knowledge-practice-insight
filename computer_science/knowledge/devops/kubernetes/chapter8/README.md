# ReplicaSets

* Redundancy: Multiple running instances mean failure can be tolerated.
* Scale: Multiple running instances means that more requests can be handled.
* Sharding: Different replicas can handle different parts of a computation in
  parallel.

A ReplicaSet acts as a cluster-wide Pod manager, ensuring that the right types
and number of Pods are running at all times. Because ReplicaSets make it easy to
create and manage replicated sets of Pods, they are the building blocks used to
describe common application deployment patterns and provide the underpinnings of
self-healing for our application at the infrastructure level. Pods managed by
ReplicaSets are automatically rescheduled under certain failure conditions such
as node failures and network partitions.

## Reconciliation loops

The central concept behind a reconciliation loops is the notion of desired state
and observed or current state. The reconciliation loop is constantly running,
observing the current state of the world and taking action try to make the
observed state match the desired state.
One of the key themes that runs through Kubernetes is decoupling. In particular,
it's important that all of the core concept of Kubernetes are modular with
respect to each other and that they are swappable and replaceable with other
components.

ReplicaSets create and manage Pods, they do not own the Pods they create.
ReplicaSets use label queries to identify the set of Pods they should be
managing.

### Designing with ReplicaSets

ReplicaSets are designed to represent single, scalable microservice inside your
architecture. They key characteristic of ReplicaSets is that every Pod that is
created by the ReplicaSet controller is entirely homogeneous. Typically, these
Pods are then fronted by a Kubernetes service load balancer, which spreads
traffic across the Pods that make up the service.

refer to [kuard_rs.yaml](./kuard_rs.yaml) for ReplicaSet demo.

```shell
kubectl scale kuard --replicas=4
kubectl autoscale rs kuard --min=2 --max=5 --cpu-percent=80
kubectl delete rs kuard
 kubectl delete rs kuard --cascade=false
```
