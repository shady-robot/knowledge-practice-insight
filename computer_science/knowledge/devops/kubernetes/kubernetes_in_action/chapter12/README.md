# Securing the Kubernetes API server

The authentication plugins are enabled through command-line options when
starting the API server.

An authentication plugin returns the username and groups of the authenticated
user.Kubernetes distinguishes between two kinds of clients connecting to the API
server:

* Actual human(users)
* Pods(application running inside)

Users are meant to be managed by an external system, such as a Single Sign
On(SSO) system, but the pods use a mechanism called `service accounts`, which
are created and stored in the cluster as ServiceAccount resources.

Service Account usernames are formatted like this:
`system:serviceaccount:<namespace>:<service account name>`. The API server
passed this username to the configured authorization plugins, which determine
whether the action the app is trying to perform is allowed to be performed by
the ServiceAccount.

Each pod is associated with exactly one ServiceAccount, but multiple pods can
use the same ServiceAccount. You can assign a ServiceAccount to a pod by
specifying the account's name in the pod manifest. If you don't assign it
explicitly, the pod will use the default ServiceAccount in the namespace.

When a request bearing the authentication token is received by the API server,
the server uses the token to authenticate the client sending the request and
then determines whether or not the related ServiceAccount is allowed to perform
the requested operation. The API server obtains this information from the
system-wide authorization plugin configured by the cluster administrator.

A ServiceAccount's image pull Secrets behave slightly differently than its
mountable Secrets. Adding image pull Secrets to a ServiceAccount saves you from
having to add them to each pod individually.

## Role-based access control

The Kubernetes API server can be configured to use an authorization plugin to
check whether an action is allowed to be performed by the user requesting the
action. An authorization plugin such as RBAC, which runs inside the API server,
determine whether a client is allowed to perform the requested verb on the
requested resource or not.

### RBAC resources

The RBAC authorization rules are configured through four resources, which can
grouped into two groups:

* Roles and ClusterRoles, which specify which verbs can be performed on which
  resources.
* RoleBindings and ClusterRoleBindings, which bind the above roles to specific
  users, groups, or ServiceAccounts.

### Using Roles and RoleBindings

A Role resource defines what actions can be taken on which resources.

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  # Rioles are namespaced(if namespace is omitted, the current namespace is used)
  namespace: foo
  name: service-reader
rules:
  # Services are resource in the core apiGroup, which has no name - hence the ""
  - apiGroups: [""]
  # Getting individual Services(by name and listing all of them is allowed.
    verbs: ["get", "list"]
    resources: ["services"]
```

```shell
$ kubectl create clusterrolebinding cluster-admin-binding --clusterrole=cluster-admin --user=your.email@address.com

kubectl create rolebinding test --role=service-reader --serviceaccount=foo:default -n foo
```

A Role defines what actions can be performed, but it doesn't specify who can
perform them. To do that, you must bind the Role to a subject, which can be a
user, a ServiceAccount, or a group. To bind a Role to a user instead of a
ServiceAccount, use the `--user` argument to specify the username. To bind it
to a group, use `--group`.

### Using ClusterRoles and ClusterRoleBindings

Roles and RoleBindings are namespaced resources, meaning they reside in and
apply to resources in a single namespace, but, RoleBindings can refer to
ServiceAccounts from other namespaces, too. A ClusterRole is a cluster-level
resource for allowing access to non-namespaced resources or non-resource URLs
or used as a common role to be bound inside individual namespaces, saving you
from having to redefine the same role in each of them.

```shell
kubectl create clusterrole pv-reader --verb=get,list --resource=persistentvolumes
kubectl create clusterrolebinding pv-test --clusterrole=pv-reader --serviceaccount=foo:default -n foo
curl localhost:8001/api/v1/persistentvolumes
```

#### Allowing access to non-resource urls

Accessing to non-resource URLs is done for you automatically through the
`system:discovery` ClusterRole and the identically named ClusterRoleBinding.

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:
  annotations:
    rbac.authorization.kubernetes.io/autoupdate: "true"
  labels:
    kubernetes.io/bootstrapping: rbac-defaults
  name: system:discovery
rules:
- nonResourceURLs:
  - /api
  - /api/*
  - /apis
  - /apis/*
  - /healthz
  - /livez
  - /openapi
  - /openapi/*
  - /readyz
  - /version
  - /version/
  verbs:
  - get
```

