# SRE related to Devops

## DevOps

DevOps is a set of practices, guideline and culture designed to break down
siloization in IT development, operations, networking, and security.
CALMS - which stands for Culture, Automation, Lean, Measurement, and Sharing.

* Reduce organization silence(No more silos)
  * Siloization of teams
  * Siloization of knowledge

* Accept failure as normal(Accidents are normal)

  Accidents are not just a result of the isolated actions of an individual, but
  rather result from missing safeguards for when things inevitably go wrong.
  It's more profitable to focus on speeding recovery than preventing accidents.

* Implement gradual change

  Chang is best when it is small and frequent. Change is risky, true, but the
  correct response is to split up your changes into smaller subcomponents where
  possible. Then you build a steady pipeline of low-risk change out of regular
  output from product design, and infrastructure changes.

* Leverage tooling & automation

  Tooling is an important component of DevOps, particularly given the emphasis
  on managing change correctly, change management relies on highly specific
  tools. A good culture can work around broken tooling, but the opposite rarely
  holds true.

* Measure everything

  You establish the reality of what's happening by means of objective
  measurement, verify that you're changing the situation as you expect, and
  create an objective foundation for conversations that different functions
  agree upon.

## SRE

* Define availability
* Level of availability
* Plan in case of failure

* SLIs are Service Level Indicator or metrics over time which inform about the
  health of a service.
* SLOs are Service Level Objectives which are agreed upon bounds for how often
  those SLIs must be met.
* SLAs are business-level agreements which define the service availability for
  a customer and the penalties for breaking that availability.

SLIs drives SLOs which inform SLAs.

To achieve 100% availability, is expensive and technically complex.

### Principles

#### Operations is a software problem

Using software engineering approaches to solve the problem. This is across a
wide field of view, encompassing everything from process and business change to
similarly complicated but more traditional software problems.

### Manage by Service Level Objectives(SLOs)

The product team and the SRE team select an appropriate availability target for
the service and its user base, and the service is managed to that SLO. We
believe that if a machine can perform a desired operation, then a machine often
should. Toil is not the job - any time spent on operational tasks means time not
spent on project work - and project work is how we make our services more
reliable and scalable.

### Work to minimize toil

Any manual, structurally mandated operational task is abhorrent. We believe that
if a machine can perform a desired operation, then a machine often should.
