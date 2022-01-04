# ETCD in kubernetes

## Set up ETCD manually

## ETCD kubeadm

```shell
kubectl exec etcd-master -n kube-system etcdctl get / --prefix --keys-only
```

ETCDCTL is the CLI tool used to interact with ETCD. ETCDCTL can interact with
ETCD Server using 2 API versions - Version 2 and Version 3. By default its set
to use Version 2.

```shell
export ETCD_API=3

etcdctl snapshot save
etcdctl endpoint health
etcdctl get
etcdctl put
```

Apart from that, you must also specify path to certificate files so that ETCDCTL
can authenticate to the ETCD API Server. The certificate files are available in
the etcd-master at the following path.

```text
--cacert /etc/kubernetes/pki/etcd/ca.crt
--cert /etc/kubernetes/pki/etcd/server.crt
--key /etc/kubernetes/pki/etcd/server.key

kubectl exec etcd-master -n kube-system -- sh -c "ETCDCTL_API=3 etcdctl get /
--prefix --keys-only --limit=10
--cacert /etc/kubernetes/pki/etcd/ca.crt
--cert /etc/kubernetes/pki/etcd/server.crt
--key /etc/kubernetes/pki/etcd/server.key"
```
