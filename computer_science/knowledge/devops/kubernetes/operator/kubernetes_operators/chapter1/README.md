# Operators empower kubernetes

## kubernetes

### kubernetes planes

* The control plane
  A collection of pods comprises the control plane and implements the Kubernetes
  application programming interface(API) and cluster orchestration logic.
* The application plane, or data plane
  Pods that dedicated to running applications.

The `controllers` of the control plane implement control loops that repeatedly
compare the desired state of the cluster to its actual state. When the two
diverge, a controller takes action to make them match. Operator extend this
behavior.

An Operator extends Kubernetes to automate the management of the entire
lifecycle of a particular application. Operators serve as a packaging mechanism
for distributing applications on Kubernetes, and they monitor, maintain,
recover, and upgrade the software they deploy.

Reducing operations effort and cost, increasing service reliability, and
spurring innovation by freeing teams from repetitive maintenance work.

## Operators are software SREs

Site Reliability Engineering(SRE) is a set of patterns and principles for
running large systems. An Operator is like an automated Site Reliability
Engineering for its application. It encodes in software the skills of an expert
administrator.

Operator work by extending the Kubernetes control plane and API. An Operator
adds an endpoiint to the Kubernetes API, called a custom resource(CR), along
with a control plane component that monitors and maintains resources of the new
type.

### Kubernetes CRs

CRs are the API extension mechanism in Kubernetes. A custome resource
definition(CRD) defines a CR, it's analogous to a schema for the CR data. CRs
provide endpoints for reading and writing structure data. A cluster user can
interact with CRs with kubectl or another Kubernetes client, just like another
API resource.

An Operator is a custom Kubernetes controller watching a CR type and taking
application-specific actions to make reality match the `spec` in that resource.
Making an Operator means creating a CRD and providing a program that runs in a
loop watching CRs of that kind.

### Who for

The Operator pattern arose in response in infrastructure engineers and
developers wanting to extend Kubernetes to provide features specific to their
site and software. Application developers build Operators to manage the
application they delivering, simplifying the deployment and management
experience on their customers' Kubernetes clusters. Infrastructure engineers
create Operators to control deployed services and systems.
