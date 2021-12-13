# Running Operators

etcd is a distributed key-value store with roots at CoreOS, now under the
auspices of the Cloud Native Computing Foundation. It is the underlying data
store at the core of Kubernetesm and a key piece of several distributed
applications. etcd provides reliable storage by implementing a protocol call
Raft that guarantees consensus among a quorum of members.

## CRs: Custom API Endpoints

A CRD defines the types and values within an instance of a CR.

The CRD defines how the Kubernetes API should reference this new resource. The
shortened nicknames that help you a little less typing in `kubectl` are
defined here.

Most Operators follow the basic pattern: a CR specifies some desired state, such
as the version of an application, and a custom controller watches the resource,
maintaining the desired state on the cluster.
