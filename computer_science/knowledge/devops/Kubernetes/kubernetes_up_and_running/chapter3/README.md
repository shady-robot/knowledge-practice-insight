# Deploying a kubernetes cluster

## Cluster components

One of the interesting aspects of Kubernetes is that many of the components that
make up the Kubernetes cluster are actually deployed using Kubernetes itself.

### Kubernetes proxy

The Kubernetes proxy is responsible for routing network traffic to load-balanced
services in the Kubernetes cluster. To do its job, the proxy must be present on
every node in the cluster. Kubernetes has an API object named DaemonSet, which
is used in many clusters to accomplished this.

`kubectl get daemonSets --namespace=kube-system kube-proxy`

### Kubernetes DNS

Kubernetes also runs a DNS server, which provides naming and discovery for the
services that are defined in the cluster. This DNS server runs as a replicated
service on the cluster.

```shell
kubectl get deployments --namespace=kube-system kube-dns
kubectl get services --namespace=kube-system kube-dns
```

### Kubernetes UI

The UI is run as a single replica, but it is still managed by a Kubernetes
deployment for reliability and upgrades.

```shell
kubectl get deployments --namespace=kube-system kubernetes-dashboard
kubectl get services --namespace=kube-system kubernets-dashboard
```