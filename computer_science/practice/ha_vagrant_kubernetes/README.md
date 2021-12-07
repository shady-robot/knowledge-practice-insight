# kubeadm-ha-stacked-vagrant / Kubernetes v1.22.1

Kubernetes Cluster: kubeadm mgmt plane + (load balancer / 3 controller ctrl
plane) + 3 executor data plane

## K8S 1.22.1

```console
                            |
                            |
                            |
┌────────────┐              ▼               ┌───────────┐
│    lb01    |------------------------------│   lb02    │
└──────┬─────┘                              └─────┬─────┘
       |                                          |
       ├────────────────────┬─────────────────────┤
       │                    │                     │
┌──────▼─────┐       ┌──────▼─────┐        ┌──────▼─────┐
│     m01    │       │     m02    │        │     m03    │
└──────┬─────┘       └──────┬─────┘        └──────┬─────┘
       │                    │                     │
       ├────────────────────┼─────────────────────┤
       │                    │                     │
┌──────▼─────┐       ┌──────▼─────┐        ┌──────▼─────┐
│     w01    │       │     w02    │        │     w03    │
└────────────┘       └────────────┘        └────────────┘
```

```shell
$ vagrant ssh c01 -c 'sudo kubectl get nodes

NAME   STATUS   ROLES                  AGE     VERSION
c01    Ready    control-plane,master   9m59s   v1.22.1
c02    Ready    control-plane,master   8m20s   v1.22.1
c03    Ready    control-plane,master   6m26s   v1.22.1
e01    Ready    <none>                 4m34s   v1.22.1
e02    Ready    <none>                 2m49s   v1.22.1
e03    Ready    <none>                 63s     v1.22.1
```
