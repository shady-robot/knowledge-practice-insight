# DaemonSets

A DaemonSet ensures that all (or some) Nodes run a copy of a Pod. As nodes are
added to the cluster, Pods are added to them. As nodes are removed from the
cluster, those Pods are garbage collected. Deleting a DaemonSet will clean up
the Pods it created.

The motivation for replicating a Pod to every node is to land some sort of agent
or daemon on each node, and the Kubernetes object for achieving this is the
DaeminSet.

refer to [kuard_ds.yaml](./kuard_ds.yaml) for demo.
