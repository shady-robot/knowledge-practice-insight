# Microservices

Microservices are independently deployable services modeled around a business domain. They communicate with each other via networks, and as an architecture choice offer many options for solving the problems you may face.

1. Independent Deployability

Independent deployability is the idea that we can make a change to microservice and deploy it into a production environment without having to utilize any other services.

Ensure our service are loosely coupled, which means we need explicit, well-defined, and stable contracts between services. 

2. Modeled Around a business domain

Making a change across a process boundary is expensive. Changes in functionality are primarily about changes in business functionality. Our business domain becomes the primary force driving our system architecture, hopefully making it easier to make changes, and making it easier for us to organize our teams around our business domain.

3. Own their own data

If one service wants to access data held by another service, then it should go and ask that service for the data it needs. This gives the service the ability to decide what is shared and what is hidden.

## Challenge of Monolithic Architectures

The monolith, be it a single-process monolith or distributed monolith, is often more vulnerable to the perils of coupling. The challenge of confused lines of ownership, which would be referred as delivery contention.

> A structure is stable if cohesion is high, and coupling is low.

Understanding the balancing forces between coupling and cohesion is important when defining microservice boundaries. Coupling speaks to how changing one thing requires a change in another; cohesion talks to how we group related code.

Treat the service interfaces that your microservice exposes like a user interface. Use outside-in thinking to shape the interface design in partnership with the people who will call your service.

Smaller release make for less risk. There is less to go wrong. If something does go wrong, working out what went wrong and how to fix it is easier because we changed less. Finding ways to reduce the side of release goes to the heart of continuous delivery, which espouses the importance of fast feedback and release-on-demand methods.

