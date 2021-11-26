# StatefulSets

StatefulSet represents a set of pods with consistent identities. Identities are
defined as:

* Network: A single stable DNS and hostname.
* Storage: As many VolumeClaims as requested. The StatefulSet guarantees that a
  given network identity will always map to the same storage identity.

ReplicaSets create multiple pod replicas from a single pod template. While a
StatefulSet makes sure pods are rescheduled in such a way that they retain their
identity and state. It also allows you to easily scale the number of pets up and
down.

Each pod created by a StatefulSet is assigned an ordinal index(zero-based),
which is then used t derive the pod's name and hostname, and to attach stable
storage to the pod.

A StatefulSet requires you to create a corresponding governing headless Service
that's used to provide the actual network identify to each pod. Through this
Service, each pod gets its own DNS entry, so its peers and possibly other
clients in the cluster can address the pod by its hostname.

When a pod instance managed by a StatefulSet disappears, the Statefulset makes
sure it's replaced with a new instance - similar to how ReplicaSets do it.
But in contrast to ReplicaSets, the replacement pod gets the same name and
hostname as the pod that has disappeared.

Each stateful pod instance need to use its own storage, plus if a stateful pod
is rescheduled, the new instance must have the same storage attached to it.

The StatefulSet has to create the PersistentVolumeClaims as well, the same way
it's creating the pods. A StatefulSet can also have one or more volume claim
templates, which enable it to stamp out PersistentVolumeClaims along with each
pod instance. The PersistentVolumes for the claims can either be provisioned
up-front by an administrator or just in time through dynamic provisioning of
PersistentVolumes.

Kubernetes must thus make grate care to ensure two stateful pod instances are
never running with the same identity and are bound to the same
PersistentVolumeClaim. A StatefulSet must guarantee at-most-one semantics for
stateful pod instances. This means a StatefulSet must be absolutely certain that
a pod is no longer running before it can create a replacement pod.

One useful feature of the API server is the ability to proxy connections
directly to individual pods.

```shell
curl -X POST -d "Hey there! This greeting was submitted to kubia-0." \
localhost:8001/api/v1/namespaces/default/pods/kubia-0/proxy/

curl localhost:8001/api/v1/namespaces/default/pods/kubia-0/proxy/
curl localhost:8001/api/v1/namespaces/default/services/kubia-public/proxy/
```

## Discover peers in StatefulSet

An important requirement of clustered apps is peer discovery -- the ability to
find other members of the cluster. Each member of a StatefulSet needs to easily
find all the other members.

SRV records are used to point to hostnames and ports of servers providing a
specific service. Kubernetes creates SRV records to point to the hsotname of the
pods backing a headless service.

```shell
kubectl run -it srvlookup --image=tutum/dnsutils --rm
--restart=Never -- dig SRV kubia.default.svc.cluster.local
```

For a pod to get a list of all the other pods of a StatefulSet, all you need to
do is perform an SRV DNS lookup.

```js
const dns = require('dns');
dns.resolveSrv(serviceName, function (err, addresses) {
  // The app performs a DNS lookup to obtain SRV records.
  if (err) {
    response.end("Could not look up DNS SRV records: " + err);
    return;
  }
  var numResponses = 0;
  if (addresses.length == 0) {
    response.end("No peers discovered.");
  }
  else {
    addresses.forEach(function (item) {
      var requestOptions = {
        host: item.name,
        port: port,
        path: '/data'
      };
      httpGet(requestOptions, function (returnedData) {
  // Each pod pointed to by an SRV record is then contacted to get its data.
            numResponses++;
          response.write("- " + item.name + ": " + returnedData);
          response.write("\n");
          if (numResponses == addresses.length) {
            response.end();
          })
      })
  }
})
```

When the node disconnects from the cluster, the control plane will mark the node
as NotReady. Because the control plane is no longer getting status updates from
the node the status of all pods on that node is `Unknown`. If the node were to
come back online and report its and its pod statuses again, the pod would again
be marked as Running. But if the pod's status remains unknown for more than a
few minutes, the pod is automatically evicted from the node. This is done by the
master(the kubernetes control plane). It evicts the pod by deleting the pod
resource.