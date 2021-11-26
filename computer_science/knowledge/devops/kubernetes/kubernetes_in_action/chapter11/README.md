# Kubernetes Internals

## Architectures

![Kubernetes Architecture](./images/kubernetes_architectures.jpeg)

### Add-on components

Beside the Control Plane components and the components running on the nodes, a
few add-on components are required for the cluster.

* The Kubernetes DNS server
* The Dashboard
* An Ingress Controller
* Heapster
* the Container Network Interface network plugin

### Components communication

Kubernetes system components communicate only with the API server. They don't
talk to each other directly. The API is the only component that communicates
with the etcd.

While multiple instances of etcd and API server can be active at the same time
and do perform their jobs in parallel, only a single instance of the Scheduler
and the Controller Manager may be active at a given time - with the others in
standby mode.

The Kubelet is the only component that always runs as a regular system
component, and it's the Kubelet that then runs all the other components as pods.

## The etcd component

Kubernetes use etcd, which is a fast, distributed, and consistent key-value
store. Because it's distributed, you can run more than one etcd instance to
provide both high availability and better performance.

All kubernetes resources include a `metadata.resourceVersion` field, which
clients need to pass back to the API server when updating an object. If the
version doesn't match the one stored in etcd, the API server rejects the update.

```shell
export ETCD_POD=$(kubectl get pods -n kube-system -l=component=etcd -o=jsonpath='{ .items[*].metadata.name}')
kubectl exec $ETCD_POD -n kube-system -- sh -c "ETCDCTL_API=3 etcdctl --endpoints https://127.0.0.1:2379 --cacert /run/config/pki/etcd/ca.crt --key /run/config/pki/etcd/server.key --cert /run/config/pki/etcd/server.crt get '/registry/pods/default/kubia-0' --prefix -w simple" | auger decode
```

In earlier versions of kubernetes, data written to etcd was stored as JSON and
could easily be inspected or manipulated using standard tools such as `etcdctl`.
In kubernetes 1.6+, for efficiency reasons, much of the data is now stored in a
binary storage representation, and is non-trivial to decode-- it contains a
enveloped payload that must be unpacked, type resolved and decoded. auger
provides kubernetes developers and cluster operators with simple way to access
the binary storage data via YAML and JSON, refer to
[auger](https://github.com/jpbetz/auger)

## References

* [etcd v3 encoded values](https://stackoverflow.com/questions/45744534/etcd-v3-cant-read-encoded-values)
