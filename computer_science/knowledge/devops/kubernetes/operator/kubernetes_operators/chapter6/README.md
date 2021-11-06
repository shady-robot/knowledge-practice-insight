# Adapter Operators

The Operator SDK provides a solution to both these problems through its Adapter
Operators. Through the command-line tool, the SDK generates the code necessary
to run technologies such as Helm and Ansible in an Operator.

## The role of CRDs

CRDs allow you create domain-specific resources that correspond to your
application. Using the standard Kubernetes APIs, end users interact with these
resources to deploy and configure applications. Operators make heavy use of CRs
and use watches on these objects to react to changes as they are made.

A CRD is the specification of what constitutes a CR. In particular, the CRD
defines the allowed configuration values and the expected output that describes
the current state of the resource.

* The kind is the name of the CR type defined by the CRD.
* The api-version contains information about the group and version of the CRD,
  which is specified when creating CRS according to the CRD schema. The value
  for this argument is specified in the format `<group>/<version>`:

  * The group should identify the organization that wrote and maintains the CRD.
  * The version should follow the Kubernetes API versioning conventions.

## Helm Operator

Helm is a package manager for Kubernetes. It makes it easier to deploy
applications with multiple components, but each deployment is still a manual
process. Helm defines the Kubernetes resources that constitute an application,
such as deployments and services, in a file called a chart. Charts support
configuration variables, so you can customize application instances without
needing to edit the chart itself. There configuration values are specified in
a file named values.yaml. A Helm Operator can deploy each instance of an
application with a different version of `value.yaml`.

## Ansible Operator

The `k8s` role provides tasks for interacting with a Kubernetes cluster. Using
this module, you can write plabooks to handle the deployment of applications,
including all of the necessary supporting Kubernetes resources.

The Operator SDK provides a way to build an Operator that will run Ansible
playbooks to react to CR changes. The SDK supplies the code for the Kubernetes
pieces, such as the controller, allowing you to focus on writing the playbooks
themselves.

### Creating and deploying Ansible-based Operators

1. Create a project

  ```shell
  $ mkdir visitorapp-operator
  $ cd visitorapp-operator
  # Run the `open-sdk init` command with `ansible` plugin to initialize the project
  $ open-sdk init --plugin=ansible --domain=example.com
  ```

1. Create an API

  ```shell
  $ mkdir visitorapp-operator
  $ cd visitorapp-operator
  # Run the `open-sdk init` command with `ansible` plugin to initialize the project
  $ open-sdk init --plugin=ansible --domain=example.com
  ```

1. Create an API

```shell
$ operator-sdk create api --version v1  --kind VisitorsApp --generate-role
# Implement the ansible role logic
$ cd ./roles/visitorsapp
$ wget https://github.com/kubernetes-operators-book/chapters/releases/download/1.0.0/visitors-ansible.tgz
$ tar -zxvf visitors-ansible.tgz
```

1. Build and push the Operator image

Use the default `Makefile` targets to build and push your operator. Set `IMG`
with a pull spec for your image that uses a registry you can push to.

```shell
make docker-build docker-push IMG=<registry>/<user>/<image_name>:<tag>
# docker.io/username/visitorsapp-operator:v0.0.1
```

1. Run the Operator

```shell
# Install the CRD
$ make install

# Deploy the project to the cluster.
$ make deploy  IMG=<registry>/<user>/<image_name>:<tag>
```

1. Create a sample custom resource (CR)

```shell
 $ kubectl apply -f config/samples/ \
```
