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
specific pod, and Kubernetes will

Taints can be used to prevent scheduling of new pods(NoSchedule effect) and to
define unpreferred node(PreferNoSchedule effect) and even evit existing pods
from a node(NoExecute).
