# istio-api-gateway
Contains YAML manifests that help manage API Gateway using Istio.

Table of content:
1. [Pre-requisite](#pre-requisite)
2. [Base Setup](#base-setup)
3. [Scenario and use-cases](#scenario-and-use-cases)

## Pre-requisite

- Kubernetes Cluster
- Kubectl with updated context
- Istio demo profile setup on cluster

## Base Setup

First, We will deploy sample application and the istio API gateway as part of the base setup.  

### Deploy Sample Application and Gateway

In this demo we are going to use echo-server container image for the sample application.

Deploy sample application backend-v1 and backend-v2:

    kubectl apply -f backend-v1.yaml
    kubectl apply -f backend-v2.yaml

Now, Let's deploy istio gateway.

    kubectl apply -g gateway.yaml

## Scenario and use-cases

Here, we will apply and test different scenarios and use-cases around api-gateway feature and functionalities.

### Host based routing:

Apply use-case manifest:

    kubectl apply -f host.yaml

Cleanup:

    kubectl delete -f host.yaml

### Path based routing:

Apply use-case manifest:

    kubectl apply -f path.yaml

Cleanup:

    kubectl delete -f path.yaml

### Rate limit requests:

Apply use-case manifest:

    kubectl apply -f path.yaml
    kubectl apply -f rate-limit.yaml

Cleanup:

    kubectl delete -f path.yaml
    kubectl delete -f rate-limit.yaml

### Weight (Percentage) based routing:

Apply use-case manifest:

    kubectl apply -f weight.yaml

Cleanup:

    kubectl delete -f weight.yaml

### Authentication (JWT):

Apply use-case manifest:

    kubectl apply -f path.yaml
    kubectl apply -f auth.yaml

Cleanup:

    kubectl delete -f path.yaml
    kubectl delete -f auth.yaml

### CORS policy with pre-flight:

Apply use-case manifest:

    kubectl apply -f cors.yaml

Cleanup:

    kubectl delete -f cors.yaml
