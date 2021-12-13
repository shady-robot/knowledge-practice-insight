# ConfigMaps and Secrets

ConfigMaps are used to provide configuration information for workloads. This can
either be fine-grained information or a composite value in the form of a file.
Secrets are similar to ConfigMaps but focused on making sensitive information
available to the workload.

## Create configmap

```txt
# This is a sample config file that I might use to configure an application
parameter1 = value1
parameter2 = value2
```

```shell
kubectl create configmap my-config --from-file=my_config.txt --from-literal=extra-param=extra-value --from-literal=another-param=another-value
kubectl get configmaps my-config -o yaml
```

## Using a configmap

There are three main ways to use a ConfigMap:

* Filesystem
    You can mount a ConfigMap into a Pod. A file is created for each entry based
    on the key name. The contents of that file are set to the value.

* Envrionment variable
    A ConfigMap can be used to dynamically set the value of an environment variable.

* Command-line argument
    Kubernetes supports dynamically created the command line for a container
    baed on ConfigMAp value.

refer to [kuard-config.yaml](./kuard-config.yaml) for demo use.

## Secrets

Kubernetes has native support for storing and hanling sensitive data with care.
Secrets enable container images to be created without building sensitive data.
This allows containers to remain portable across envrionments. Secrets are
exposed to pods via explicit declaration in pod manifests and the Kubernetes
API.

```shell
kubectl create secret generic kuard-tls --from-file=kuard.crt --from-file=kuard.key
```

### Consuming secrets

Secret data can be exposed to pods using the secret volume type. Secrets volumes
are managed by the kubelet and are created at pod creation time. Secrets are
stored on tmpfs volumes and, as such, are not written to disk on nodes.
