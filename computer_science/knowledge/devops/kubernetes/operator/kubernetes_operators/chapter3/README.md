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
