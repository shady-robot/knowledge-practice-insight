# Certificate

## Certificate authority

```shell
$ openssl genrsa -out ca.key 2048
ca.key
$ openssl request -new -key ca.key -subj="/CN=KUBENETES-CA" -out ca.csr
ca.csr
$ openssl x509 -req in ca.scr -signkey ca.key -out ca.crt
ca.crt
```

## client certificates

### Admin user

```shell
$ openssl genrsa -out admin.key 2048
admin.key

$ openssl req -new -key admin.key -subj="/CN=kube-admin/O=system:masters" -out admin.csr
admin.csr

$ openssl x509 -req -in admin.csr -CA ca.crt -CAkey ca.key -out admin.crt
admin.crt

curl https://kube-apiserver:6643/api/v1/pods
--key admin.key --cert admin.crt --cacert ca.crt

# Kubeconfig
apiServer: v1
clusters:
- cluster:
    certificate-authority: ca.crt
  name: kubernetes
kind: Config
users:
- name: kubernetes-admin
  user:
    client-certificate: admin.crt
    client-key: admin.key
```

## Server side certificate

### Etcd server

`openssl x509 -in /etc/kubernetes/kpi/apiserver.crt -text -noout`

### kube controller

```shell
kubectl auth can-i create deployments
kubectl auth can-i create pods --as dev-user
```
