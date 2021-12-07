# Kubernetes RBAC

RBAC policies are vital for the correct management of your cluster, as they
allow you to specify which types of actions are permitted depending on the user
and their role in your organization.

* Secure your cluster by granting privileged operations only to admin users.
* Force user authentication in your cluster.
* Limit resource creation to specific namespaces. You can also use quotas to
  ensure that resource usage is limited and under control.
* Have a user only see resources in their authorized namespace.

## RBAC API objects

One basic kubernetes feature is that all its resources are modeled API objects,
which allow CRUD operations.

Subjects: These correspond to the entity that attempts an operation in the
cluster.

* User Accounts: These are global, and meant for humans or processes living
  outside the cluster.
* Service Accounts: This kind of account is namespaced and meant for
  intra-cluster processes running inside pods, which want to authenticate
  against the API.
* Groups: This is used for referring to multiple accounts.

## References

* [Configure RBAC in your Kubernetes Cluster](https://docs.bitnami.com/tutorials/configure-rbac-in-your-kubernetes-cluster/)
