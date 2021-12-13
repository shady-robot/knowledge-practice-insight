# Client Go

Th Kubernetes API server exposes a REST interface consumable by any client.
client-go is the official client library for the Go programming language. It is
used both internally by Kubernetes itself(for example, inside kubectl) as well
as by numberous external consumers: operators like the `etcd-operator` or
`prometheus-operator`, higher level frameworks like KubeLess and OpernShift,
and many more.

## Project layout

1. The `kubernetes` package contains the clientset to access Kubernetes API.
2. The `discovery` package is used to discover APIs supported by a Kubernetes
   API server.
3. The `dynamic` package contains a dynamic client that can perform generic
   operation on arbitrary Kubernetes API objects.
4. The `plugin/pkg/client/auth` packages contain optional authentication plugins
   for obtaining credentials from external sources.
5. The `transport` package is used to set up auth and start a connection.
6. The `tools/cache` package is useful for writing controllers.
