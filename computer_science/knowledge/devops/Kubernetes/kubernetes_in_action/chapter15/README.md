# Automatic scaling of pods and cluster nodes

Kubernetes can monitor your pods and scale them up automatically as soon as it
detects an increase in the CPU usage or some other metrics.

## Horizontal pod autoscaling

Horizontal pod autoscaling is the automatic scaling of the number of pod
replicas managed by a controlled. It's perform by the Horizontal controller,
which is enabled and configured by creating a HorizontalPodAutoscaler(HPA)
resource.

The autoscaling process can be split into three steps:

* Obtain metrics of all the pods managed by the scaled resource object.
* Calculate the number of pods required to bring the metrics to the specific
  target value.
* Update the replicas field of the scaled resource.

The HorizontalPodAutoscaler is implemented as a Kubernetes API resource and a
controller. The resource determines the behavior of the controller. The
horizontal pod autoscaling controller, running within the Kubernetes control
plane, periodically adjusts the desired scale of its target to match observed
metrics.

```yaml
$ kubectl create -f deployment.yaml
$ kubectl autoscale deployment kubia --cpu-percent=30 --min=1 --max=5
$ kubectl get hpa

# Adding request load
$ kubectl expose deployment kubia --port=80 --target-port=8080
$ kubectl run -it --rm --restart=Never loadgenerator --image=busybox -- sh -c "while true; do wget -O - -q http://kubia.default; done"
```

## Calculating the required number of pods

Once the Autoscaler has metrics for all the pods belonging to the resource the
Autoscaler is scaling, it can use those metrics to figure out the required
number of replicas. It needs to find the number that will bring the average
value of the metric across all those replicas as close to the configured target
value as possible.

### Scaling based on CPU utilization

Perhaps the most important metric you'll want to base autoscaling on is the
amount of CPU consumed by the processes running inside your pods. As far as the
Autoscaler is concerned, only the pod's guaranteed CPU amount(the CPU requests)
is important when determined the CPU utilization of a pod. The Autoscaler
compares the pod's actual CPU consumption and its CPU requests, which means the
pods you're autoscaling need to have CPU requests set(either directly or
indirectly through a LimitRange object) for the Autoscaler to determine the CPU
utilization percentage.

### Understand the maximum rate of scaling

The autoscaler has a limit on how many replicas can be added in a single
scale-up operation. The autoscaler will at most double the number of replicas in
a single operation, if more than two current replicas exist. If only one or two
exist, it will scale up to a maximum of four replicas in a single step.

Additionally, it has a limit on how soon a subsequent autoscale operation can
occurred in the last three minutes. A scale-down event is performed even less
frequently - every five minutes.

### Scaling based in memory consumption

Memory-based autoscaling is much more problematic than CPU-based autoscaling.
The main reason is because after scaling up, the old pods would somehow need to
be forced to release memory. This need to be done by the app itself - it can't
be done by the system. All the system could do is kill and restart the app,
hoping it would use less memory than before.

## Vertical pod autoscaling

The Vertical Pod Autoscaler(VPA) is a Kubernetes sub-project that provides a
vertical scaling implementation for Kubernetes controllers, such as Deployments.
It functions by tweaking the resource request parameters of the pods that make
up the workload, based on the analysis of metrics collected from the workloads.

### VPA API resource

The behavior required of VPA is declaratively defined using a custom resource
definition(CRD) called a VerticalPodAutoscaler.

## Horizontal scaling of cluster nodes

The Cluster Autoscaler takes care of automatically provisioning additional nodes
when it notices a pod that can't be scheduled to existing nodes because of lack
of resources on those nodes. It also de-provisions nodes when they're
underutilized for longer period of time.

```console
gcloud container clusters update kubia --enable-autoscaling --min-nodes=3 --max-nodes=5
```

### Limiting service disruption during cluster scale-down

Certain services require that a minimum number of pods always keeps running,
this is especially true for quorum-based clustered applications. Kubernetes
provides a way of specifying the minimum number of pods that need to keep
running while performing there types of operations. This is done by creating a
PodDisruptionBudget resource.

```shell
kubectl create pdb kubia-pdb --selector=app-kubia --min-available=3
```

## References

* [HorizontalPodAutoscaler Walkthrough](https://kubernetes.io/docs/tasks/run-application/horizontal-pod-autoscale-walkthrough/)
* [Kubernetes autoscaler](https://github.com/kubernetes/autoscaler/)
