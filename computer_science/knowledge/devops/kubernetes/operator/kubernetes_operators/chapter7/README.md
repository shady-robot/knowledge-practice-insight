# Operator with Go with the Operator SDK

The Operator SDK provides that flexibility by making it easy for developers to
use the Go programming language, including its ecosystem of external libraries,
in their Operators.

1. Create the necessary code that will tie in to Kubernetes and allow it to run
    the Operator as controller.
2. Create one or more CRDs to model the application's underlying business logic
    and provide the API for users to interact with.
3. Create a controller for each CRD to handle the lifecycle of its resources.
4. Build the Operator image and create the accompanying Kubernetes manifests to
    deploy the Operator and its RBAC components.(service accounts, roles, etc.)

## Go Operator demo

```shell

operator-sdk init --domain example.com --repo example/memcached-operator

```

### Manager

The main program for the operator `main.go` initialize and runs the Manager.
The manager registers the Scheme for the custom resource API definitions, and
sets up and runs controllers and webhooks.

### Create a new API and Controller

Create a new Custom Resource Definition(CRD) API with group `cache` version
`v1alpha1` and Kind Memcached.

```shell
operator-sdk create api --group cache --version v1alpha1 --kind Memcached --resource --controller
```

This will scaffold the Memcached resource API at `api/v1alpha1/memcached_types.go`
and the controller at `controllers/memcached_controller.go`.

In general, it's recommended to have one controller responsible for manage each
API created for the project to properly follow the design goals set by `controller-runtime`.

### Implement the Controller

```go
func (r *MemcachedReconciler) SetupWithManager(mgr ctrl.Manager) error {
    return ctrl.NewControllerManagedBy(mgr).
    For(&cachev1alpha1.Memcached{}).
    Owns(&appsv1.Deployment{}).
    Complete(r)
}
```

#### Controller configurations

The `SetupWithManager()` function specifies how the controller is built to watch
a CR and other resources that are owned and managed by the controller.

The `NewControllerManagedBy()` provides a controller builder that allows various
controller configuration.

`For(&cachev1alpha1.Memcached{})` specifies the Memcached type as the primary
resource to watch. For each Memcached type Add/Update/Delete event the reconcile
loop will be sent a reconcile `Request` for that Memcached object.

`Owns(&appsv1.Deployment{})` specifies the Deployments type ad the secondary
resource to watch. For each Deployment type Add/Update/Delete event, the event
handler will map each event to reconcile `Request` for the owner of the
Deployment.

#### Reconcile loop

The reconcile function is responsible for enforcing the desired CR state on the
actual state of the system. It runs each time an event occurs on a watched CR or
resource, and will return some value depending on whether those states match or
not.

```go
func (r *MemcachedReconciler) Reconcile(ctx context.Context, req ctrl.Request) (ctrl.Result, error) {
// Lookup the Memcached instance for this reconcile request
memcached := &cachev1alpha1.Memcached{}
err := r.Get(ctx, req.NamespacedName, memcached)
...
}
```
