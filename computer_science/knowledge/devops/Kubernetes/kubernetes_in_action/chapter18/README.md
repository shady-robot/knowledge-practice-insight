# Extending Kubernetes

## Defining custom API objects

Instead of dealing with Deployment, Services, ConfigMaps, and the like, you'll
create and manage objects that represent whole applications or software
services. A custom controller will observe those high-level objects and create
low-level objects based on them.

### CustomResourceDefinitions

The CustomResrouceDefinition object is the description of the custom resource
type. Once the CRD is posted, users can then create instances of the custom
resource by posting JOSN or YAML manifests to the API server, the same as with
any other Kubernetes resource. Each CRD will usually also have an associated
controller, the same way that all the core Kubernetes resources have an
associated controller.
