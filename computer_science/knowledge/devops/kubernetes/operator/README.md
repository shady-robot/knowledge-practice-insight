# Operator

An Operator represents human operational knowledge in software, to reliably
manage an application.

It builds upon the basic Kubernetes resource and controller concepts but
includes domain or application-specific knowledge to automate common tasks.

* Resource
    Pod/ConfigMap/Route
* Controller
    ReplicaSet/DaemonSet/Deployment
* Knowledge
    Install/Scale/Self-Heal/Backup/Metrics

Operators take advantage of Custom Resource Definitions. CRDs allow us to extend
the Kubernetes API.
A Custom Resource needs a controller to act upon its presence.

Kubrnetes Controllers:

* Observe: Current state of the cluster.
* Analyze: Compare current state to desired state.
* Act:  Perform all the actions necessary to make current state meet desired
  state.

Operator Lifecycle Magager(OLM)
Enable cluster admins to manage Operators on any Kubernetes cluster(dependency
management)

Operators make it easy to manage complex stateful applications on top of
Kubernetes. However writing an Operator today can be difficult because of
challenges such as using low level APIs, writing boilerplate, and a lack of
modularity which leads to duplication.

## Operator SDK

The Operator SDK is a framework that uses the controller-runtime library to make
writing Operator easier by providing:

* High level APIs and abstractions to write the operational logic more intuitively.
* Tools for scaffolding and code generation to bootstrap a new project fast.
* Extensions to cover common Operator use cases.

Workflow for a new Go-Based Operator with the Operator SDK.

1. Create a new Operator project using the SDK CLI.
2. Create a new Custom Resource Definition API Type using the SDK CLI.
3. Add your Custom Resource Definition (CRD) to your live Kubernetes cluster.
4. Define your Custom Resource Spec and Status.
5. Create a new Controller for your Custom Resource Definition API.
6. Write the reconciling logic for your Controller.
7. Run the Operator locally to test your code against your live Kubernetes
   cluster.
8. Add your Custom Resource (CR) to your live Kubernetes cluster and watch your
   Operator in action!
9. After you are satisifed with your work, run some Makefile commands to build
    and generate the Operator Deployment manifests.
10. Optionally add additional APIs and Controllers using the SDK CLI.

In Kubernetes, every functional object includes `spec` and `status`. Kubernetes
functions by reconciling desired state(Spec) with the actual cluster state. We
than record what is observed(Status).

## OperatorHub

Operator SDK for you to.

Helm

* Basic install
* Upgrade
* Lifecycle
* Insights
* Auto-Pilot

## Ansible Operator

A collection of building blocks from Operator DSK that enables Ansible to handle
the reconciliation logic for an Operator. Ansible Operator is one of the
available types of Operators that Operator SDK is abled to generate. Operator
SDK can create an operator using Golang, Helm, or Ansible.

Ansible Operator is an Operator which is powered by Ansible.
Custom Resource events trigger Ansible tasks as opposed to the traditional
approach of handling these events with Go code.

Ansible Operator development and testing is fully supported as a first-class
citizen within the Operator SDK. Operator SDK can be used to create new Operator
projects, test existing Operator projects, build Operator images, and generate
new Custom Resource Definitions(CRDs) from a Operator.

Why build Operators with Ansible?

### Mapping kubernetes events to Ansible automation

The Ansible Operator uses a Watches file, written in YAML, which holds the
mapping between Custom Resources and Ansible Roles/Playbooks.

The "watches" file(watches.yaml) maps a Kubernetes object to your Ansible
automation.

* Associates the Kubernetes Groups, Version, Kind(GVK) to an AnsibleRole or
  Playbook.
* The Operator SDK binary watches the cluster for matching events defined in
  the watches.yml
* Executes the associated Ansible content when an event occurs.

By default, `operator-sdk new --type ansible` creates 'watches.yaml' configured
to execute a role in response to a Custom Resource event.

```shell
operator-sdk init --plugins=ansible --domain example.com
operator-sdk create api --group cache --version v1alpha1 --kind Memcached --generate-playbook
```

```yaml
# watches.yaml
---
version: v1alpha1
group: cache.example.com
kind: Memcached
playbook: /path/to/playbook

apiVersion: <Group/Version>
kind: <kind>
metadata:
  name: <name>
spec:
  <key>:<value>
status:
  <key>:<value>
```

* spec: values will be translated to Ansible `extra_vars`
* status: will be a generic status recorded by the ansible Operator SKD operator.
  This will use ansible-runner output to generate meaningful information for
  the user.

| File/Folders  | Purpose   |
|---|---|
| config  | Kustomize YAML definitions required to launch our controller on a cluster. It is the target directory to hold our CustomResourceDefinitions, RBAC configuration, and WebhookConfigurations.  |
| Dockerfile  | The container build file used to build your Ansible Operator container image.  |
| Makefile  | Make targets for building and deploying your controller  |
| molecule  | Used for Ansible Based Operator Testing  |
| playbooks  |  Placeholder for possible ansible playbook  |
| PROJECT | Kubebuilder metadata for scaffolding new components |
| requirements.yaml | requirements.yaml for defining an Ansible collection. |
| roles | Contains an Ansible Role initialized using Ansible Galaxy |
| watches.yaml | Contains Groups, Version, Kind, Ansible invocation method. |
