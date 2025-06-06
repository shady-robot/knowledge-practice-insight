# GCP Cloud

## Cloud Computing

1. Customer get computing resources that are on-demand and self-service.
2. Customers get access to those resources over the internet, from anywhere.
3. The provider of those resources allocates them to uses out of that pool.
4. Resources are elastic, which means they're flexible, so customers can scale up or down as needed.
5. Customers pay only for what they use, or reserve as they go.

## IaaS

1. Raw compute.
2. Storage
3. Network Capability

## Google Infrastructure Security

1. Hardware Infrastructure Security
   1. Hardware design and provenance
   2. Secure boot stack
   3. Premises Security
2. Service Deployment Layer
   1. Encryption of inter-service communication
3. User Identity Layer
   1. User Identity
   2. Universal 2nd Factor(U2F)
4. Storage Service Layer
   1. Encryption at rest
5. Internet Communication Layer
   1. Google Front End("GFE")
   2. Denial of Service("DoS) protection
6. Operational Security Layer
   1. Intrusion detection
   2. Reducing insider risk
   3. Employee Universal Second Factor use
   4. Software development practice

## Google Cloud Resource Hierarchy

The resource hierarchy directly relates to how policies are managed and applied on Google Cloud.

Projects are the basis for enabling and using the Google Cloud services, like managing APIs, enabling billing, adding and removing collaborators, and enabling other Google services.

Each project is a separate entity under the organization node, and each resource belongs to exactly one project. Projects can have different owners and users because they're billed and managed separately.

Each Google Cloud project has three identifying attributes:

* A project ID: A globally unique identifier assigned by Google that can't be changed after creation.
* A project name: A human-readable name that can be changed.
* A project number: Google Cloud assigns each project a unique project number.

Use folders to group projects under an organization in a hierarchy. Folders can be nested to create a hierarchy of projects.

## IAM policy

Administrators can apply policies that define who(principal) can do what(rule) on which resources.

The "can do what" part of an IAM policy is defined by role. An IAM role is a collection of permissions.

Specific Google Cloud service offer sets of predefined roles, and they even define where those roles can be applied.

## Service Account

Service accounts allow you to assign specific permissions to a virtual machine, so it can interact with other cloud services without human intervention. Service accounts are named with an email address, but instead of passwords they use cryptographic keys to access resources.

With Cloud Identity, organizations can define policies and manage their users and groups using the Google Admin console. Admin can log in and manage Google Cloud resources using the same usernames and passwords they already use in existing Active Directory or LDAP systems.

## Virtual Private Cloud

A virtual private cloud, or VPC, is a secure, individual, private cloud-computing model hosted within a public cloud. The VPC combine the scalability and convenience of public cloud computing with the data isolation of private cloud computing.

## Cloud Load Balancing

Cloud Load Balancing is a fully distributed, software-define, managed service for all your traffic. You can put Cloud Load Balancing in front of all your traffic: HTTP or HTTPS, other TCP and SSL traffic, and UDP traffic too. Cloud Load Balancing provides cross-region load balancing, including automatic multi-region failover, which gently moves traffic in fractions if backends become unhealthy.

## Cloud Storage Option

### Cloud Storage

Which is a service that offers developers and IT Organizations durable and highly available storage. Object storage is a computer data storage architecture that manages data as "object" and not as a file and folder hierarchy, or as chunks of disk.

Cloud Storage's primary use is whenever binary large-object storage(also, known as a "BLOB") is needed for online content. Cloud Storage files are organized into buckets. A bucket needs a globally unique name and a specific geographic location for where it should be stored, and an ideal location for a bucket is where latency is minimized.

Controlling access to stored data is essential to ensuring security and privacy are maintained. Cloud Storage offers a variety of access control mechanisms, including IAM policies, bucket policies, and object-level permissions.

1. Standard Storage
2. Nearline Storage
3. Coldline Storage
4. Archive Storage

* Unlimited storage
* Worldwide accessibility and locations.
* Low latency and high durability.
* A uniform experience.
* Geo-redundancy

Cloud Storage also provide a feature called Autoclass, which automatically transitions objects to appropriate storage classed based on their access patterns. Autoclass simplifies and automates cost saving for your Cloud Storage data.

## GKE

With the Autopilot mode, which is recommended, GKE manages the underlying infrastructure such as node configuration, autoscaling, autoscaling, auto-upgrades, baseline security configuration, and baseline networking configuration.

### Advanced cluster management features:

1. Google Cloud's load-balancing for Compute Engine instance.
2. Node pools to designate subnets of nodes within a cluster.
3. Automatic scaling of your cluster's node instance count.
4. Automatic upgrade for your cluster's node software.
5. Node auto-repair to maintain node health and availability.
6. Logging and monitoring with Google Cloud Observability.

## Cloud Run

1. Write your code
2. Build and package
3. Deploy to Cloud Run

Cloud Run will starts your container on demand to handle requests, and ensures that all incoming requests are handled by dynamically adding and removing containers.

Cloud Run functions:

1. Lightweight, event'driven, asynchronous compute solution.
2. Allows you to create small, single-purpose functions that respond to cloud events without the need to manage a server or a runtime environment.
3. Construct application workflows from individual business logic tasks and connect and extend cloud services.
4. Billed to the nearest 100 milliseconds, and only while your code is running.
5. Supports writing source code in a number of programming languages, include Node.js, Python, Go, Java.
6. Events from Cloud Storage and Pub/Sub can trigger Cloud Run Functions asynchronously, or use HTTP invocation for synchronous execution.

LLMs are large, general-purpose language models that can be pre-trained and then fine-tuned for specific purpose.

A Prompt is the text that you feed to the model, and prompt engineering is a way of articulating your prompts to get the best response from the model.
