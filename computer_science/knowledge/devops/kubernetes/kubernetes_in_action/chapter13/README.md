# Securing cluster nodes and the network

## Using the host node's namespace in a pod

Contaienrs in a pod usually run under separate Linux namespaces, which isolate
their processes from processes running in other containers or in the node's
default namespaces.

Certain pods need to operate in the host's default namespaces, allowing them to
see and manipulate node-level resources and devices.

A related features allows pods to bind to a port in the node's default
namespace, but still have their own network namespace. This is done by using
`hostPort` property in one of the container's ports defined in the
`spec.containers.ports` field.

The pod's containers will use the node's PID and IPC namespaces, allowing
processes running in the containers to see all the other processes on the node
or communicate with them through IPC.

```yaml
spec:
  hostPID: true
  hostIPC: true
  containers:
  - image: luska/kubia
    name: kubia
    ports:
    - containerPort: 8080
      hostPort: 9000
      protocol: TCP
```

## Container's security context

To set the pod's `securityContext.runAsUser` property. You need to specify a
user ID, not a username.

```yaml
spec:
  containers:
  - name: main
    image: alpine
    command: ["/bin/sleep", "99999"]
    securityContext: 405

    # Preventing running as root
    securityContext:
      runAsNonRoot: true

    # Run in priviledged mode
    securityContext:
      privileged: true
```

Sometimes pods need to do everything that the node they're running on can do,
such as use protected system devices or other kernel features, which aren't
accessible to regular containers. To get full access to the node's kernel, the
pod's container runs in privileged mode.

* `securityContext.capabilities.add`: Add capabilities to give it access only to
  the kernel features it really requires.
* `securityContext.capabilities.drop`: you can drop some capabilities.
* `securityContext.readOnlyRootFilesystem`: Prevent the container from writing
  to its filesystem, but not the mounted volumes.

Sharing volumes when containers run as different users.
Kubernetes allows you to specify supplemental groups for all the pods running in
the container, allowing them to share files, regardless of the user IDs they're
running as.

## Restricting the use of security-related features in pods

The cluster admin can restrict the use of security-related features by creating
one or more PodSecurityPolicy resources. PodSecurityPolicy is a cluster-level
resources, which defines what secturoty-related features users can or can't use
in their pods. The job of uploading the policies configured in PodSecurityPolicy
resources is performed by the PodSecurityPolicy admission control plugin running
in the API server.

When someone posts a pod resources to the API server, the PodSecurityPolicy
admission control plugin validates the pod definition against the configured
PodSecurityPolicies.

```yaml
apiVersion: extensions/v1beta1
kind: PodSecurityPolicy
spec:
  allowedCapabilities:
  - SYS_TIME
  defaultAddCapabilities:
  - CHOWN
  requiredDropCapabilities:
  - SYS_ADMIN
  - SYS_MODULE
```

The `SYS_ADMIN` capability allows a range of administrative operations, and the
`SYS_MODULE` capability allows loading and uploading Linux kernel modules.

## Isolating the pod network

A NetworkPolicy applies to pods that match its label selector and specifies
either which sources can access the matched pods or which destinations can be
accessed from the matched pods. This is configured through ingress and egress
rules, respectively.
