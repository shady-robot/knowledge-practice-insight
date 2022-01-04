# Certified Kubernetes Administrator

## Resources

* [Certified Kubernetes Administrator](https://www.cncf.io/certification/cka/)
* [Exam Curriculum (Topics):](https://github.com/cncf/curriculum)
* [Candidate Handbook](https://www.cncf.io/certification/candidate-handbook)
* [Exam Tips](http://training.linuxfoundation.org/go//Important-Tips-CKA-CKAD)

## Certification tip

### Imperative way

* Create an NGINX Pod

`kubectl run nginx --image=nginx`

* Generate POD Manifest YAML file.

`kubectl run nginx --image=nginx --dry-run=client -o yaml`

* Create a deployment

`kubectl create deployment --image=nginx nginx`

* Generate deployment YAML file

`kubectl create deployment --image=nginx nginx --dry-run=client =o yaml`

* Specify replicas

```yaml
kubectl create deployment --image=nginx nginx --replicas=4 --dry-run=client -o
yaml > nginx-deployment.yaml
```

* Scale a deployment

`kubectl scale deployment nginx --replicas=4`

* Create a service

```shell
kubectl expose pod redis --port=6379 --name redis-service --dry-run=client` -o yaml

kubectl create service clusterip redis --tcp=6379:6379 --dry-run=client -o yaml

kubectl expose pod nginx --type=NodePort --port=80 --name=nginx-service --dry-run=client -o yaml
```

1. Find pods by labels

`kubectl get all -l env=prod,bu=finance --no-headers | wc -l`

refer more example on [kubectl usage conventions](https://kubernetes.io/docs/reference/kubectl/conventions/).

### Namespaces

`kubectl config set-context $(kubectl config current-context)` --namespace=prod

### Taints and toleration

```yaml
kubectl taint nodes node-name key=value:taint-effect
kubectl taint nodes node1 app=blue:NoSchedule

taint-effect:
- NoSchedule
- PreferNoSchedule
- NoExecute
```

Node Affinity Types:

requiredDuringSchedulingIgnoredDuringExecution
preferredDuringSchedulingIgnoredDuringExecution

```shell
kubectl  get nodes  node01 --show-labels --no-headers | awk '{ print $6 }'| awk -F',' '{print NF}'
```

## References

* [How to Pass the Certified Kubernetes Administrator](https://www.youtube.com/watch?v=mHnBAt9Uqdk)
* [Kubernetes the hard way](https://acloudguru.com/course/kubernetes-the-hard-way)
