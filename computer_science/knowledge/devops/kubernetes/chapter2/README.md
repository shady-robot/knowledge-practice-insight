# Creating and running containers

Kubernetes is a platform for creating, deploying, and managing distributed
application. Applications are typically comprised of a language runtime,
libraries, and your source code. In many case your application relies on
external libraries such as `libc` and `libssl`. These external libraries are
generally shipped as shared components in the OS that you have installed on a
particular machine.

Container images bundle an application and its dependencies, under a root
filesystem, into a single artifacts. A container image is a binary package that
encapsulates all of the file necessary to run an application inside of an OS
container.

## The docker image format

Standardize the container image format via the Open Container Image(OCI)
project. The Docker image format continues to be the de facto standard, and is
made up of series of filesystem layer in the filesystem.

Container images are constructed of a series of filesystem layers, where each
layer inherits and modifies the layers that came before it.
Container images are typically combine with a container configuration file,
which provides instructions on how to set up the container environment and
execute an application entrypoint.

Container categories:

* System containers

  System containers seek to mimic virtual machines and often run a full boot
  process.
* Application containers

  Application containers commonly run a single application. By running single
  application, it provides the perfect level of granularity for composing
  scalable applications, and is a design philosophy that is leverage heavily
  by pods.

## Building application images with docker

### Dockerfile

A Dockerfile can be used to automate the creation of a Docker container image.
The true power of Docker comes from the ability to share images across thousands
of machines and the broader Docker community.

### Image Secutiry

Best practice for packaging and distributing applications.

### Optimizing image size

Files that are removed by subsequent layers in the system are actually still
present in the images, they're just inaccessible.

Each layer is an independent delta from the layer below it. Changing the
preceding layers means that they need to be rebuilt, repushed, and repulled to
deploy your image to development.

### Storing images in remote registry

Kubernetes relies on the fact that images described in a pod manifest are
available across every machine in the cluster.

## The docker container runtime

Kubernetes provides an API for describing an application deployment, but relies
on a container runtime to set up application container using the
container-specific APIs native to the target OS. On a Linux system that means
configuring `cgroups` and namespaces.

```shell
docker run -d --name kuard --publish 8080:8080 \
--memory 200m --memory-swap 1G --cpu-shares 1024 \
gcr.io/kuar-demo/kuard-amd64:1
```
