# Helm

Helm allows users to more simply deploy and manage the life cycle of Kubernetes
applications. It abstracts many of the complexities behind configuring
Kubernetes applications and allows teams to be more productive on the platform.
Container orchestration is about placing containers on certain machines from a
pool of compute resources based on their requirements.

Helm is an open source tool used for packaging and deploying applications on
Kubernetes. Packaging managers are used to simplify the process of installing,
upgrading, reverting, and removing a system's applications.

A Helm chart can be thought of as a Kubernetes package. Charts contain the
declarative Kubernetes resource files required to deploy an application.

```shell
$ helm repo add bitnami https://charts.bitnami.com/bitnami
$ helm install redis bitnami/redis --namespace=redis --set
  master.persistence.size=10Gi --set replica.persistence.size=10Gi
$ helm upgrade redis bitnami/redis --namespace=redis
$ helm rollback redis 1 --namespace=redis
$ helm status redis -n redis
$ helm history redis -n redis
$ helm uninstall redis --namespace=redis
```

## The benefits of Helm

* Abstracting the complexity of Kubernetes resources
* Maintaining an ongoing history of revisions
* Configuring declarative resources in a dynamic fashion
* Simplifying local and live state synchronization
* Deploying resources in an intelligent order(resource creation order)
* Provide automated life cycle hooks

## Authentication

Helm needs to be able to authenticate with a Kubernetes cluster to deploy and
manage applications. It authenticates by referencing a `kubeconfig` file, which
specifies different Kubernetes clusters and how to interact with them. Since
Helm authenticates to Kubernetes using the credentials defined in the
`kube-config` file, Helm is given the same level of access.

## Helm charts

Helm charts can be made available for consumption by publishing them to a chart
repository. A chart repository is a location where packaged charts can be stored
and shared.

To make it easier to find chart repositories(and other Kubernetes-related
artifacts), the Kubernetes community created a platform called Artifact Hub.
Artifact Hub is a centralized location for upstream Kubernetes artifacts, such
as Helm charts, operations, plugins and more.

```shell
helm search hub wordpress --max-col-width=0
helm repo add bitnami https://raw.githubus.com/bitnami
helm repo list
helm search repo bitnami --output yaml
helm search repo wordpress
```

### Helm install charts

```shell
$ helm install wordpress bitnami/wordpress --values=wordpress-values.yaml
    --namespace chapter3 --version 12.1.6
$ helm show values bitnami/wordpress --version 12.1.6

$ helm get manifest
# To return the manifest for a named release

$ helm get nodes
# To return the notes for a named release

$ helm get all
# To return all the information about a named release.
```

When secrets need to be provided, the recommended approach is to use the
`--set` flag to prevent them from being committed to source control.

### Helm history

```shell
$ helm upgrade wordpress bitnami/wordpress --values wordpress-values.yaml
    -n chapter3 --version 12.1.6
$ kubectl get secrets -n chapter3
$ helm get values wordpress --revision 3 -n chapter3
$ helm rollback wordpress 3 -n chapter3
```
