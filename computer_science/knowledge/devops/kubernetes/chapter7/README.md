# Service Discovery

Service discovery tools help solve the problem of finding which processes are
listening at which addresses for which services. An abstract way to expose an
application running on a set of Pods as a network service. Kubernetes gives Pods
their own IP addresses and a single DNS name for a set of Pods, and can
load-balance across them.

The Domain Name System(DNS) is the traditional system of service discovery on
the internet. DNS is designed for relatively stable name resolution with wide
and efficient caching.

## The service object

In Kubernetes, a Service is an abstraction which defines a logical set of Pods
and a policy by which to access them. The set of Pods targeted by a Service is
usually determined by a selector.

Real service discovery in Kubernetes starts with a Service object. A Service
object is a way to create a named label selector.

```shell
kubectl create service nodeport alpaca-prod --tcp=8080:8080
```

This specification creates a new Service object named "my-service", which
targets TCP port 9376 on any Pod with the app=MyApp label. Kubernetes assigns
this Service an IP address which is used by the Service proxies.

```yaml
apiVersion: v1
kind: Service
metadata:
  name: my-service
spec:
  selector:
    app: MyApp
  ports:
    - protocol: TCP
      port: 80
      targetPort: 9376
```

## Service DNS

Kubernetes provides a DNS service exposed to Pods running in the cluster. This
Kubernetes DNS service was installed as a system component when the cluster was
first created. The Kubernetes DNS service provides DNS names for cluster IPs.

`alpaca-prod.default.svc.cluster.local.`

alpaca-prod: The name of the service in question.
default: The namespace that this service is in.
svc: Recognizing that this is a service.
cluster.local: The base domain name for the cluster.

The most portable way to do this is to use a feature called NodePorts, which
enhance a service even further. In addition to a cluster IP, the system picks
a port(or the user can specify one), and every node in the cluster then forward
to that port to the service.

## Virtual IPs and service proxies

Every node in a Kubernetes cluster runs a `kube-proxy`. `kube-proxy` is
responsible for implementing a form of virtual IP for Services of type other
than `ExternalName`.

## References

* [Kubernetes Imperative Command](https://kubernetes.io/docs/tasks/manage-kubernetes-objects/imperative-command/)
