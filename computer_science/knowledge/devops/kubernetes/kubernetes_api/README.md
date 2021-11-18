# Kubernetes Objects

Kubernetes objects are persistent entities in the Kubernetes system. Kubernetes
uses these entities to represent the state of your cluster.

A Kubernetes object is a "record of intent" -- once you create the object, the
Kubernetes system will constantly work to ensure that object exists. By creating
an object, you've effectively telling the Kubernetes system what you want your
cluster's workload to look like, this is your cluster's desired state.

## Object Spec and Status

`spec`: providing a description of the characteristic you want the resource to
have: its desired state.
`status`: describes the current state of the object, supplied and updated by the
Kubernetes system and its components.

## Describing a Kubernetes object

When you create an object in Kubernetes, you must provide the object spec that
describe its desired state, as well as some basic information about the object.

### Required Fields

* apiVersion: Which version of the Kubernetes API you're using to create this
  object.
* kind: What kind of object you want to create.
* metadata: Data the helps uniquely identify the object, including a `name`
  string, `UID` and optional `namespace`
* `spec`: What state you desire for the object.
