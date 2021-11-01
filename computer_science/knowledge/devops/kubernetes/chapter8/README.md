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
