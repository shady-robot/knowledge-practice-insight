# Istio

## Install Istio via helm

```sh
$ helm repo add istio https://istio-release.storage.googleapis.com/charts
$ helm repo update

$ kubectl create namespace istio-system
$ helm install istio-base istio/base -n istio-system --set defaultRevision=default

$ helm ls -n istio-system
$ helm install istiod istio/istiod -n istio-system --wait
$ helm ls -n istio-system
$ helm status istiod -n istio-system
$ kubectl get deployments -n istio-system --output wide
```

## API Gateway

An API gateway acts as an intermediary between client and backend services like a reversed proxy. It accepts the API request, processes it by combining the necessary
services, and returns the appropriate result which helps with API management.

An API gateway behaves as a single point of entry into the system for microservices-based applications. It is responsible for request routing, composition, and policy enforcement. Some of its other features include authentication, authorization, monitoring, load balancing, and response handling.

1. API governance
   API gateway provides a unified interface for managing and governing APIs across an organization. They offer capabilities such as API versioning, rate limiting, request throttling, and caching, ensuring consistent and controlled access to APIs.
2. Security and authentication
   API gateways serve as a security layer, protecting backend services from unauthorized access and potential threats.
3. Traffic management and load balancing
   API gateways distribute incoming requests across multiple backend services to ensure load balancing and improve performance.
4. Service composition and aggregation
   API gateway enable the composition of multiple backend services into a single API, simplifying the client-side integration progress. They can aggregate data from multiple services, combine response, or transform the data structure to meet the specific requirements of the client.

## Istio Gateway

Istio gateway acts as the entry point for external traffic into the service mesh, allowing fine-grained control over traffic routing and enabling advanced features such as load balancing, SSL/TLS termination, and access control.

1. Service mesh
   * It has resilience mechanisms like timeouts, retries, circuit-breaking, etc.
   * Service clients can get more details regarding the topology of the architecture like client-side load balancing, service discovery and request routing. 
2. API gateways
   * It aggregates APIs, abstract APIs, and exposes them.
   * It provides zero-trust security policies at the edge based on the user such as tight control over data in/out using Allowed Headers and Requests.
   * It also helps to bring security trust domains using JWT or OAuth/SSO.  

### Istio virtual service

Istio Virtual Service is used to define the routing rules and policies for incoming traffic within the service mesh. It allows you to configure how requests are routed to specific services and endpoints based on various criteria such as HTTP headers, URL paths, and weights. A single virtual service is also used for sidecars inside the mesh.
Virtual Services enable features like traffic splitting, traffic mirroring, load balancing, and fault injection.

### Istio Destination Rule

The Istio Destination Rule complements the functionality of Virtual Service by defining the policies and settings specific to a particular service or version. It provides a
way to configure the behavior of the traffic as it reaches the destination service. Destination Rules allow you to define traffic load balancing algorithms, connection pool settings, circuit breakers, TLS settings, and other service-specific configuration.

### Istio Ingress gateway

Istio Ingress Gateway is a component of Istio that allows you to expose services outside of the service mesh. It is a load balancer that sits at the edge of the mesh
and receives incoming HTTP/TCP connections. It can be used to expose services to the public internet, or to other internal networks.

## References

* [Istio - Install with Helm](https://istio.io/latest/docs/setup/install/helm/)
* [Simplify your API management using Istio as API Gateway](https://www.infracloud.io/blogs/simplify-api-management-istio-api-gateway/)