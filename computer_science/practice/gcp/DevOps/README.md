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