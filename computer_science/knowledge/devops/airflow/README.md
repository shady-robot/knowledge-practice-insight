# Airflow Overview

Airflow is a platform that lets you build and run workflows. A workflow is
represented as a DAG(a Directed Acyclic Graph), and contains individual pieces
of work called Tasks, arranged with dependencies and data flows taken into
account.

A DAG specifies the dependencies between Tasks, and the order in which to
execute them and run retries, the Tasks themselves describe what to do, be it
fetching data, running analysis, triggering other systems.

* A scheduler, which handles both triggering scheduled workflows, and submitting
  Tasks to the executor to run.
* An executor, which handles running tasks. In the default Airflow installation,
  this runs everything inside the scheduler, but most production-suitable
  executors actually push task execution out to workers.
* A webserver, which presents a handy user interface to inspect, trigger and
  debug the behaviour of DAGs and tasks.
* A folder of DAG files, read by the scheduler and executor(and any workers the
  executor has)
* A metadata database, used by the scheduler, executor and webserver to store
  state.

![Airflow Architecture](./images/airflow_architecure.png)

## Workloads

A DAG runs through a series of Tasks, and there are three common types of task
you  will see:

* Operators, predefined tasks that you can string together quickly to build most
  parts of your DAGs.
* Sensors, a special subclass of Operator which are entirely about waiting for
  an external even to happen.
* A TaskFlow-decorated @task, which is custom Python function packaged up as a
  Task.

Operators and Sensors are templates, and when you call one in a DAG file, you're
making a Task.

## Control Flow

DAGs are designed to be run many times, and multiple runs of them can happen in
parallel. DAGs are parameterized, always including an interval they are
"running for", but with other optional parameters as well. By default, a task
will wait for all its upstream tasks to succeed before it runs, but his can be
customized using features like `Branching`, `LatestOnly`, and `Trigger Rules`.

To pass data between tasks you have three options:

* XComs("Cross-communications"), a system where you can have tasks push and pull
  small bits of metadata.
* Uploading and downloading large files from a storage service.
* TaskFlow API automatically passes data between tasks via implicit XComs.

Airflow sends out Tasks to run on Workers as space becomes available, so there's
no guarantee all the tasks in your DAG will run on the same worker or the same
machine.

## User Interface

Airflow comes with a user interface that lets you see what DAGs and their tasks
are doing, trigger runs of DAGs, view logs, and do some limited debugging and
resolution of problems with your DAGs.
