# Introduction

Kubernetes is an open source orchestrator for deploying containerized
applications. Kubernetes provides the software necessary to successfully build
and deploy reliable, scalable distributed systems.

## Velocity

Velocity is the key component in nearly all software development today. Velocity
is measured not in terms of the raw number of features you can ship per hour or
day, but rather in terms of the number of things you can ship while maintaining
a highly available service.

### The value of Immutability

Container and Kubernetes encourage developers to build distributed system that
adhere to the principles of immutable infrastructure. Immutable container images
are at the core of everything that you will build in Kubernetes.

### Declarative configuration

Everything in Kubernetes is a declarative configuration object that represents
the desired state of the system. It is Kubernetes's job to ensure that the
actual state of the world matches this desired state.

The combination of declarative state stored in a version control system and
Kubernetes' ability to make reality match this declarative state makes rollback
of a change trivially easy.

### Self-Healing systems

Kubernetes is an inline, self-healing system. It continuously takes actions to
ensure that the current state matches the desire state. Self-healing systems
like Kubernetes both reduce the burden on operators and improve the overall
reliability of the system by performing reliable repairs more quickly.

## Scaling your service and your teams

Kubernetes achieves scalability by favoring decoupled architectures.

### Decoupling

In a decoupled architecture each component is separated from other components
by defined APIs and service load balancers. APIs provides a buffer between
implementer and consumer, and load balancers provide a buffer between running
instances of each service.

Decoupling servers via APIs makes it easier to scale the development teams
because each team can focus on a single, smaller microservice with a
comprehensible surface are. (avoid communication overhead)

### Easy scaling for applications and clusters

The immutable, declarative nature of Kubernetes makes this scaling trivial to
implement. Because your containers are immutable, and the number of replicas is
simply a number in a declarative config, scaling your service upward is simply
a matter of changing a number in a configuration file, asserting this new
declarative state to Kubernetes and letting it take care of the reset.

### Scaling development teams with microservice

The development of decoupled, service-oriented teams that each build a single
microservice.

Kubernetes provides numerous abstractions and APIs that make it easier to build
these decoupled microservice architectures.

* Pods, or groups of containers, can group together container images developed
  by different teams into a single deployable unit.
* Kubernetes service provide load balancing, naming, and discovery to isolate
  one microservice from another.
* Namespaces provide isolation and access control, so that each microservice can
  control the degree to which other services interact with it.
* Ingress objects provide an easy-to-use frontend that can combine multiple
  services into a single externalized API surface area.

### Separation of Concerns for Consistency and Scaling

An important aspect of this decoupling is that the container orchestration API
becomes a crisp contract that separates the responsibilities
of the application operator from the cluster orchestration operator.
This decoupling of concerns means that a small team running a Kubernetes cluster
can be responsible for supporting hundreds or even thousands of teams running
application within that cluster.

## Abstract your infrastructures

The move to application-oriented container APIs like Kubernetes has two concrete
benefits. It separates developers from specific machines. It also enables a high
degree of portability since developers are consuming a higher-level API that is
implemented in terms of the specific cloud infrastructure APIs.

When your developer build their applications in terms of container images and
deploy them in terms of portable Kubernetes APIs, transferring your application
between environments, or even running in hybrid environments, is simple a matter
of sending the declarative config to a new cluster.

## Efficiency

Efficiency can be measured by the ratio of the useful work performed by a
machine or process to the total amount of energy spent doing so. When discussing
efficiency, it's often helpful to think of both the cost of running a server and
the human cost required to manage it.

Kubernetes provides tools that automate the distribution of applications across
a cluster of machines, ensuring higher levels of utilization than are possible
with traditional tooling.

Reducing the cost of development instances in your stack enables development
practices that might previously have been cost-prohibitive.
