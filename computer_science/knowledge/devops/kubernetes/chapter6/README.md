# Labels and annotations

Labels are key/value pairs that can be attached to Kubernetes objects such as
Pods and ReplicaSets. Labels provide the foundation for grouping.

Annotations, on the other hand, provide a storage mechanism that resembles
labels: annotations are key/value pairs designed to hold noidentifying
information that can be leveraged by tools and libraries.

## Labels

Labels provides identifying metadata for objects. These are fundamental
qualities of the object that will be used for grouping, viewing and operating.

The key/value pairs where both key and value are represented by strings.
Label keys can be broken down into two parts: an optional prefix and a name,
separated by a slash.

```yaml
kubectl create deployment alpaca-prod \
    --image=gcr.io/kuar-demo/kuard-amd64:1 \
    --replicas=2
kubectl label deployment alpaca-prod  ver=1 app=alpaca env=prod --overwrite
```

### Label selectors

Label selectors are used to filer Kubernetes objects based on a set of labels.

```yaml
kubectl get deployment --show-labels
kubectl get deployment --selector="app in (alpaca, bandicoot)"
kubectl get deployment --selector="ver=2,env!=test"
```

![Kubernetes Label Selector](./ kubernetes_label_selector.png)

When a kubernetes object refers to a set of other Kubernetes objects, a label
selector is used.

## Annotations

Annotations provide a place to store additional metadata for Kubernetes objects
with the sole purpose of assisting tools and libraries. While labels are used to
identify and group objects, annotations are used to provide extra information
about where an object came from, how to use it, or policy around that object.

Annotations are used in various places in Kubernetes, with the primary use case
being rolling deployments. During rolling deployments, annotations are used to
track rollout status and provide the necessary information required to roll back
a deployment to previous state.

Labels and annotations are key to understand how key components in a Kubernetes
cluster work together to ensure the desired cluster state. Using labels and
annotations properly unlocks the true power of Kubernetes's flexibility and
provides the starting point for building automation tools and deployment
workflows.
