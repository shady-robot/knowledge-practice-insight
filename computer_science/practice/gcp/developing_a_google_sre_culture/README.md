# Site Reliability Engineering

Site Reliability Engineering(SRE) is the practice of balancing the velocity of
development features with the risk to reliability.

![SRE Principles](./images/SRE_principles.png)

How to think about, measure, and incentivize reliability.

1. Reduce organizational silos.(increase and foster collaboration by breaking down barriers across teams)
2. Accept failure is normal
3. Implement gradual change
4. Leverage tooling and automation
5. Measure everything

With regard to reducing organizational silos, SREs share ownership of production with developers. Together they define service level objectives or SLOs and error budgets, and share responsibility of how they determine reliability and prioritize work.

SREs focus on tail automation reducing the amount of manual repetitive work.

1. DevOps emerged to help close gaps and break down silos between development and operation teams.
2. DevOps is philosophy, not a development methodology or technology.
3. SRE is a practical way to implement DevOps philosophy.
4. SRE consist of both technical and cultural practices.

The performance of your service relative to SLOs should guide your business decisions.
(Accepting failure as normal and reducing organizational silos)

## The mission of SRE

To protect, provide for, and progress software and systems with
consistent focus on availability, latency, performance, and capacity.

SRE teams focus on practices such as automation, learning from failure, and reducing the cost of failure.

Incentivize automation with time for creativity. Launching and iterating allows teams to fail fast.

## Postmortems

Blameless postmortems are a tenet of SRE culture. For a postmortem to be truly blameless, it must focus on identifying
on contributing causes of the incident without indicating any individual or team for bas or inappropriate behavior.

### The components of postmortem

* Details of the incident and its timeline
* The actions taken to mitigate or resolve the incident.
* The incident's impact
* Its trigger and root cause or causes
* The follow-up actions to prevent its recurrence

After the outage, it's important to understand why an incident occurred, and then take steps to make sure it doesn't happen again in the same way. SREs do this by documenting and conducting a blameless postmortem.

A Postmortem's ultimate deliverable is a written record of the incident that consist of specific parts.(Every failure is an opportunity to learn, and Good SREs are constructive pessimists, and a lot of their instincts come from experiencing past failure.)

1. Framework as learning problem and not an execution problem.
2. Acknowledge your own fallibility.
3. Model curiosity(make sure that yourself ask a lot of questions)

### Impacts of psychologically safe environment

1. Bridge is encouraged.
2. Cooperation is high
3. Messengers are not punished when delivering bad news.
4. Failure is treated as opportunity for improvement.
5. New ideas are welcomed.

Psychological safety plays a key role in boosting SRE team dynamics, and also directly influencing operational excellence and software delivery.

Hindsight bias is the tendency of people to overestimate their ability to have predicated an outcome, even though it could not have
possibly been predicted.

Discomfort discharge is when people blame others to discharge discomfort and pain at a neurobiological level.

Blamelessness is the notion of switching responsibility from people to systems and processes.
In short, don't focus on people, focus on systems, and processes to better support people making the right choices when designing and maintaining complex systems.

### SLOs and error budgets

SRE employs practice that effectively break down these silos and promote shared ownership between development and operations teams.

Error Budget: The amount of unreliability you are willing to tolerate.

Failure are documented in postmortems, which focus on systems and
processes versus people.
(As long as the measured up time is above your target, meaning as long as you have error budget remaining, you can push new feature releases.)

It creates a shared responsibility between teams for system uptime, as infrastructure failures take away developer's error budget.
SRE practice that ties to error budgets and creates shared responsibility between dev and ops teams are server-level objectives, or SLOs.

SLO(Service-level objectives)s are precise numerical target for system reliability.

SLIs(Service-level indicators) are metrics that measure the performance of a system relative to the SLOs. It's a quantifiable measure of service reliability.



