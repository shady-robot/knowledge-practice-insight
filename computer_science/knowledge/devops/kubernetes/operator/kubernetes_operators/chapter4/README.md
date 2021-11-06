# The Operator Framework

The Red Hat Operator Framework makes it simpler to create and distribute
Operators. It makes building Operators easier with a software development kit
(SDK) that automates much of the repetitive implementation work. The Framework
also provides mechanisms for deploying and managing Operators.

* Operator SDK for building and developing Operators.
* Operator Lifecycle Manager(OLM) is an Operator that installs, manages, and
  upgrades other Operators.
* Operator Metering is a metrics system that accounts for Operator's use of
  cluster resources.

The Operator SDK builds atop the Kubernetes controller-runtime, a set of
libraries providing essential Kubernets controller routines in the Go programming
language.

## Operator Maturity Model

![operator maturity model](./operator-maturity-model.png)

## Operator SDK

The Operator SDK is a set of tools for scaffolding, building, and preparing an
Operator for deployment. The SDK currently includes first-class support for
constructing Operators in the Go programming language, with support for other
languages planned.

The SDK imposes a standard project layout, and in return create skeletal Go
source code for the basic Kubernetes API controller implementation and
placeholders for your application-specific handlers. Form there, the SDK provides
convenience commands for building an Operator and wrapping it in a Linux
container, generating the YAML-format Kubernetes manifests needed to deploy the
Operator on Kubernetes clusters.

## Operator Lifecycle Manager

Operators address the general principle that any application, on any platform,
must be acquired, deployed, and managed over time.

Operator Lifecycle Manager takes the Operator pattern on level up the stack: it's
an Operator that acquires, deploys, and manages Operators on a Kubernetes
cluster. Like an Operator for any application, OLM extends Kubernetes by way of
custom resources and custom controllers so that Operators, too, can be managed
declaratively, with Kubernetes tools, in terms of the Kubernetes API.

OLM defines a schema for Operator metadata, called the Cluster Service
Version(CVS), for describing an Operator and its dependencies. Operator with a
CVS can be listed as entries in a catalog available to OLM running on a
Kubernetes cluster.

Based on the description and parameters an Operator provides in its CVS, OML can
manage the Operator over its lifecycle: monitoring its state, taking actions to
keep it running, coordinating among multiple instances on a cluster, and
upgrading it to new version. The Operator, in turn, can control its application
with the latest automation features for the apps's latest versions.

## Operator Metering

Operator Metering is a system for analyzing the resource usage of the Operators
running on Kubernetes clusters. Metering analyzes Kubernetes CPU, memory, and
other resource metrics to calculate costs for infrastructure services. Metering
provides a model for ops teams to map the costs of a cloud service or a cluster
resource to the application, namespace, and team consuming it.

