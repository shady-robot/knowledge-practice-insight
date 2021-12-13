//
// main.go
package main

import (
	"context"
	"flag"
	"fmt"
	"time"

	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/rest"
	"k8s.io/client-go/tools/clientcmd"
)

func main() {
	kubeconfig := flag.String("kubeconfig", "/Users/shady/.kube/config", "localtion to your kubeconfig file")
	config, err := clientcmd.BuildConfigFromFlags("", *kubeconfig)

	// Customize config settings
	config.Timeout = 120 * time.Second
	if err != nil {
		// handle error here
		config, err = rest.InClusterConfig()
		if err != nil {
			fmt.Printf("error %s, getting inclusterconfig\n", err.Error())
		}
	}

	namespace := "default"
	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		// handle error
		fmt.Printf("error %s, creating clientset\n", err.Error())
	}
	pods, err := clientset.CoreV1().Pods(namespace).List(context.Background(), metav1.ListOptions{})
	if err != nil {
		// handle
		fmt.Printf("error %s, while listing all the pods from %s namespace\n", err.Error(), namespace)
	}

	fmt.Printf("Pods from namespace %s:\n ", namespace)
	for _, pod := range pods.Items {
		fmt.Printf("Pod name: %s\n", pod.Name)
	}

	fmt.Println()
	deployments, err := clientset.AppsV1().Deployments(namespace).List(context.Background(), metav1.ListOptions{})
	if err != nil {
		fmt.Printf("error %s, while listing all the deployments from %s namespace\n", err.Error(), namespace)
	}

	for _, deployment := range deployments.Items {
		fmt.Printf("Deployment name: %s\n", deployment.Name)
	}
}
