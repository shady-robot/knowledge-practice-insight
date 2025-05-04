# Istio

## Install Istio via helm

```sh
$ helm repo add istio https://istio-release.storage.googleapis.com/charts
$ helm repo update

$ kubectl create namespace istio-system
$ helm install istio-base istio/base -n istio-system --set defaultRevision=default

$ helm ls -n istio-system
$ helm install istiod istio/istiod -n istio-system --wait
$ helm ls -n istio-system
$ helm status istiod -n istio-system
$ kubectl get deployments -n istio-system --output wide
```

## API Gateway


## References

* [Istio - Install with Helm](https://istio.io/latest/docs/setup/install/helm/)