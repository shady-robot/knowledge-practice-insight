# Advanced scheduling

Kubernetes allows you to affect where pods are scheduled.

## Taints and tolerations

A pod can only be scheduled to a node if it tolerates the node's taints. Node
selectors and node affinity rules make it possible to select which nodes a pod
can or can't be scheduled to by specifically adding that information to the pod,
whereas taints allow rejecting deployment of pods to certain nodes by only
adding taints to the node without having to modify existing pods.

### taints

The master node has a single taint. Tains have a key, value, and an effect, and
are presented as `<key>=<value>:<effect>`.

```text
Taints: node-role.kubernetes.io/master:NoSchedule

key: node-role.kubernetes.io/master
value: null
effect: NoSchedule
```

This taint prevents pods from being scheduled to the master node, unless those
pods tolerate this taint. The pods that tolerate it are usually system pods.

Each taint has an effect associated with it.

* NoSchedule, which means pods won't be scheduled to the node if they don't
  tolerate the taint.
* PreferNoSchedule is a soft version of NoSchedule, meaning the scheduler will
  try to avoid scheduling the pod to the node, but will schedule it to the node
  if it can't schedule it somewhere else.
* NoExecute, unlike NoSchedule and PreferNoSchedule that only affect scheduling,
  also affects pods already running on that node.  If you add a NoExecute taint
  to a node, pods that are already running on that node and don’t tolerate the
  NoExecute taint will be evicted from the node.

Adding custom taints to a node, to add a taint, you use the kubeclt taint
command: `kubectl taint node node1.k8s node-type=production:NoSchedule`.

Adding tolerations to pods.

```yaml
apiVersion: extensions/v1beta1
kind: Deployment
metadata:
  name: prod
spec:
  replicas: 5
  template:
    spec:
      ...
      tolerations:
      - key: node-type
        Operator: Equal
        value: production
        effect: NoSchedule
# The pod tolerate the node being notReady for 300 seconds,
# before it needs to be rescheduled.
      - key: node.alpha.kubernetes.io/notReady
        operator: Exists
        effect: NoExecute
        tolerationSeconds: 300
```

## Node affinity

A mechanism called node affinity, which allows you to tell Kubernetes to
schedule pods only to specific subsets of nodes.

By specifying a preference, you tell Kubernetes which nodes you prefer for a
specific pod, and Kubernetes will try to schedule the pod to one of these nodes.
If not possible, it will choose one of the other nodes.

Taints can be used to prevent scheduling of new pods(NoSchedule effect) and to
define unpreferred node(PreferNoSchedule effect) and even evicted existing pods
from a node(NoExecute).

### Specifying hard node affinity rules

```yaml
spec:
  nodeSelector:
    gpu: "true"

spec:
  affinity:
    nodeAffinity:
      requiredDuringSchedulingIgnoreDuringExecution:
        nodeSelectorTerms:
        - matchExpressions:
          - key: gpu
            operator: In
            values:
            - "true"
```

The nodeSelector field specifies that the pod should only be deployed on nodes
that include the `gpu=true` label.

* `requiredDuringScheduling` means the rules defines under this field specify
  the labels the node must have for the pod to be scheduled to the node.
* `IgnoredDuringExecution` means the rules defined under the field don't affect
  pods already executing on the node.

The `SelectorSpreadPriority` function, which make sure pods belonging to the
same ReplicaSet or Service are spread around different nodes so a node failure
won't bring the whole service down.

## Pod affinity

By specifying the affinity between pods themselves, you can co-locate pods
together, which, reducing latency and improving the performance.

```yaml
spec:
  affinity:
    podAffinity:
      requiredDuringSchedulingIgnoredDuringExecution:
      - topologyKey: kubernetes.io/hostname
        labelSelector:
          matchLabels:
            app: backend
```

### Expressing pod affinity preference instead of hard requirements

You can tell the Scheduler you'd prefer to have your frontend pods scheduled
onto the same node as your backend pod, but if that's not possible, you're okay
with them being scheduled elsewhere.

```yaml
spec:
  affinity:
    podAffinity:
      preferredDuringSchedulingIgnoredDuringExecution:
      - weight: 80
        podAffinityTerm:
          topologyKey: kubernetes.io/hostname
          labelSelector:
            matchLabels:
              app: backend
```

## Pod anti-affinity

Using pod anti-affinity to keep pods away from each other. It's specified the
same way as pod affinity, except that you use the podAntiAffinity property
instead of podAffinity, which results in the Scheduler never choosing nodes
where pods matching the podAffinity's label selector are running.

### Using anti-affinity to spread apart pods of the same deployment

```yaml
spec:
  affinity:
    podAntiAffinity:
      requiredDuringSchedulingIgnoredDuringExecution:
      - topologyKey: kubernetes.io/hostname
        labelSelector:
          machLabels:
            app: frontend
```

## Summary

* If you add a taint to a node, pods won't be scheduled to that node unless they
  tolerate that taint.
* Three types of taints exist: NoSchedule completely prevents scheduling,
  PreferNoScheduler isn't as strict, and NoExecute even evicts existing pods
  from a node.
* Node affinity allows you to specify which nodes a pod should be scheduled to.
  It can be used to specify a hard requirement or to only express a node
  preference.
* Pod affinity is used to make the Scheduler deploy pods to the same node where
  another pod is running.(based on the pod's labels)
* Pod affinity's topologyKey specifies how close the pod should be deployed to
  the other pod.
* Pod anti-affinity can be used to keep certain pods away from each other.
* Both pod affinity and anti-affinity, like node affinity, can either specify
  hard requirements or preferences.
