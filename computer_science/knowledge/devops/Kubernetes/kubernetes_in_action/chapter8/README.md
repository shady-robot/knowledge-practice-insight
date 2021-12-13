# Accessing pod metadata

## Downward API

Kubernetes Downward API allows you to pass metadata about the pod and its
environment through environment variables or files. The Downward API enables you
to expose the pod's own metadata to the processes running inside that pod.

* The pod's name
* The pod's IP address
* The namespace the pod belongs to
* The name of the node the pod is running on
* The name of the service account the pod is running under
* The CPU and memory requests for each container
* The CPU and memory limits for each container
* The pod's labels
* The pod's annotations

### Environment variables

Pass the pod's and container's metadata to the container through environment
variables.

```yaml
- name: POD_NAMESPACE
  valueFrom:
    fieldRef:
      fieldPath: metadata.namespace
```

When your process runs, it can look up all the environment variables you defined
in the pod spec.

### DownwardAPI volume

You can define a downwardAPI volume and mount it into your container. You must
use a downwardAPI volume for exposing the pod's labels or its annotations,
because neither can be exposed through environment variables.

```yaml
volumeMounts:
- name: downward
  mountPath: /etc/downward
volumes:
- name: downward
  downwardAPI:
    items:
    - path: "podName"
      fieldRef:
        fieldPath: metadata.name
    - path: "annotation"
      fieldRef:
        fieldPath: metadata.annotations
    - path: "containerMemoryLimitBytes"
      resourceFieldRef:
        containerName: main
        resource: limits.memory
        divisor: 1
```

When you change the labels and annotations dynamically, Kubernetes updates the
files holding them, allowing the pod to always see up-to-date data. This also
explain why labels and annotations can't be exposed through environment
variables.

Using the DownwardAPI allows you to keep the application Kubernetes-agnostic.
This is especially useful when you're dealing with an existing application that
expects certain data in environment variables. The Downward API allows you to
expose the data to the application without having to rewrite the application or
wrap it in a shell script.

## Kubernetes API

The kubectl proxy command runs a proxy server that accepts HTTP connections on
your local machine and proxies them to the API server while taking cate of
authentication.

```shell
export CURL_CA_BUNDLE=/var/run/secrets/kubernetes.io/serviceaccount/ca.crt
TOKEN=$(cat /var/run/secrets/kubernetes.io/serviceaccount/token)
curl -H "Authorization: Bearer $TOKEN" https://kubernetes
```

Process inside pod to access the Kubernetes API:

1. The app should verify whether the API server's certificate is signed by the
   certificate authority, whose certificate is in the ca.crt file.
2. the app should authenticate itself by sending the Authorization header with
   the bearer token from the token file.
3. The namespace file should be used to pass the namespace to the API server
   when performing CRUD operations on API objects inside the pod's namespace.

An ambassador container can be used to hide the complexities of connecting to an
external service and simplify the app running in the main container.
