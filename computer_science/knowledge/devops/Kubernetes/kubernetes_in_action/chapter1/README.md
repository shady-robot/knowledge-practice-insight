# Introducing Kubernetes

Kubernetes abstracts away the hardware infrastructure and exposes your whole
data-center as a single enormous computational resource.

Microservices communicate through synchronous protocols such as HTTP, over
which they usually expose RESETful APIs, or through asynchronous protocols
such as AMQP.

By abstracting away the actual hardware and exposing it as a single platform
for deploying and running apps, it allows developers to configure and deploy
their applications without any help from the sysadmins and allows the sysadmins
to focus on keeping the underlying infrastructure up and running, while not
having to know anything about the actual applications running on top of it.

The actual isolation of containers is done at the Linux kernel level using
kernel features such as Linux Namespaces and cgroups. Docker only makes it easy
to use those features.

Kubernetes is a software system that allows you to easily deploy and manage
containerized applications without having to know any internal details of these
applications and without having to manually deploy theses applications on each
host.

## The kubernetes Components

* The master node, which hosts the Kubernetes Control Plane that controls and
  manages the whole Kubernetes system
* Worker nodes that run the actual application you deploy

### The Control Plane

The Control Plane is what controls the cluster and makes it function.

* The Kubernetes API server, which you and the other Control Plane components
  communicate with.
* The Scheduler, which schedules your apps
* The Controller Manager, which performs cluster-level functions, such as
  replicating components, keeping track of worker nodes, handling node failures,
  and so on.
* etcd, a reliable distributed data store that persistently stores the cluster
  configuration.

## Benefits of using Kubernetes

1. Simplifying application deployment

   All the nodes are a single bunch of computational resources that are waiting
for application to consume them.

2. Achieving better utilization of hardware

   Decouple your app from the infrastructure. The ability to move applications
   around the cluster at any time, providing by containers, allows Kubernetes to
   utilize the infrastructure much better than you can achieve manually.

3. Health checking and self-healing

   Kubernetes monitors your app components and the nodes they run on and
   automatically reschedules them to other nodes in the event of a node failure.

4. Automatic scaling

   Kubernetes can automatically scale the whole cluster size up or down based on
   the needs of the deployed application, if additional nodes is as easy as
   requesting them through the cloud provider's API.

5. Simplifying application development

   The apps run in the same environment both during development and in
   production.
