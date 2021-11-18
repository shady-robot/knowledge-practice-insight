# Controller Runtime Client API

The `controller-runtime` library provides various abstractions to watch and
reconcile resources in a Kubernetes cluster via CRUD(Create, Update, Delete, as
well as Get and List in this case) operations. Operators use at least one
controller to perform a coherent set of tasks within a cluster, usually through
a combination of CRUD operations. The Operator SDK use controller-runtime's
Client interface, which provide the interface for these operations.

controller-runtime defines several interfaces used for cluster interaction:

* `client.Client`: Implementers perform CRUD operations on a Kubernetes cluster.
* `manager.Manager`: Manages shared dependencies, such as Caches and Clients.
* `reconcile.Reconciler`: Compares provided state with the actual cluster state
    and updates the cluster on finding state differences using a Client.

## Client usage

### Default client

The SDK relies on a `manager.Manager` to create a `client.Client` interface
that performs CRUD operations within a `reconcile.Reconciler`'s Reconcile
function. The SDK will generate code to create a Manager, which holds a Cache
and a Client to be used in CRUD operations and communicate with the API server.
