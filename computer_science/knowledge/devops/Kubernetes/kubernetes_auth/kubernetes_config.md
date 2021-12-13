# Kubeconfig file

Use kubeconfig files to organize information about cluster, users, namespaces,
and authentication mechanisms. A file that is used to configure access to
clusters is called a kubeconfig file.

## Context

A context element in a kubeconfig file is used to group access parameters under
a convenient name. Each context has three parameters: cluster, namespace,
and user.

```shell
kubectl config use-context
kubectl config view
```

The `KUBECONFIG` environment variables holds a list of kubeconfig file.
