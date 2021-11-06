# Operator at Kubernetes Interface

Operators extends two key concepts: resources and controllers. The Kubernetes
API includes a mechanism, the CRD, for defining new resources.

An Operator is the application-specific combination of CRs and a custom
controller that does know all the detail about starting, scaling, recovering and
managing its application. The Operator's operand is what we call the
application, services, or whatever resources an Operator manages.

## Custom Resources

CRs, as extensions of the Kubernetes API, contain one or more fields, like a
native resource, but are not part of a default Kubernetes deployment. CRs hold
structured data, and the API server provides a mechanism for reading and setting
their fields as you would those in native resource, by using kubectl or another
API cluent. Users define a CR on a running cluster by providing a CR definition.
A CRD is akin to a schema for a CR, defining the CR's fields and the types of
values those fields contain.

ConfigMap are best at providing a configuration to a program running in a Pod on
the cluster - think of an application's config file. Applications usually want
to read such configuration from within their pod, as a file or the value of an
environment variable, rather than from the Kubernetes API.

## Custom Controllers

CRs are entries in the Kubernetes API database. To provide a declarative API for
a specific application running on a cluster, you also need active code that
capture the processes of managing that application.

## Namespace

* Namespace scope
  Restricting your Operator to a single namespace.

* Cluster-scoped
  Watch and manage an application or services throughout a cluster.

## Authorization

Authorization - The power to do things on the cluster through the API - is
defined in Kubernetes by one of a few available access control systems.
Role-Based Access Control(RBAC) is the preferred and most tightly integrated of
these. EBAC regulates access to system resources according to the role a system
user performs.
