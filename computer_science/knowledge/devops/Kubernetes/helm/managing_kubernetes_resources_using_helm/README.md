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

