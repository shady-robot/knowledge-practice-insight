# Common kubectl commands

The `kubectl` common-line utility is a powerful tool to create objects and
interact with the Kubernetes API.

## Namespaces

Kubernetes uses namespaces to organize objects in the cluster.

## Contexts

If you want to change the default namespace more permanently, you can use a
context. This gets recorded in a kubectl configuration file, usually located
at `$HOME/.kube/config` This configuration file also stores how both find and
authenticate to your cluster.

```shell
kubectl config set-context my-context --namespace=mystuff
kubectl config use-context my-context
```

## Viewing kubernetes API objects

Everything contained in Kubernetes is represented by a restful resource. Each
Kubernetes object exist at a unique HTTP path. The kubectl command make HTTP
requests to these URLs to access the Kubernetes objects that reside at these
paths.

By default, kubectl uses a human-readable printer for reviewing the response
from the API server, but this human-readable printer removes many of the details
of the objects to fit each object on one terminal line. kubectl uses the
JSONPath query language to select fields in the returned object.

```shell
kubectl get <resource_name> <object_name>
kubectl get -o wide  <resource_name> <object_name>
kubectl get -o json <resource_name> <object_name>
kubectl get -o yaml <resource_name> <object_name>
kubectl get -o yaml --no-headers <resource_name> <object_name>
kubectl get <resource_name> <object_name> -o jsonpath --template={.status.podIP}
```

## Creating, updating, and destroying kubernetes objects

Objects in the Kubernetes API are represented as JSON or YAML files. These files
are either returned by the server in response to query or posted to the server
as part of an API request. You can use these YAML or JSON files to create,
update, delete objects on the Kubernetes server.

```shell
kubectl apply -f obj.yaml
kubectl edit <resource-name><obj-name>
kubectl delete -f obj.yaml
kubectl delete <resource-name><obj-name>
```

### Debuging commands

```shell
kubectl logs <pod-name>
kubectl exec -ti <podname> -- bash
kubectl cp <pod-name>:/path/to/remote/file /path/to/local/file
```
