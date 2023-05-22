# DAGs

A DAG(Directed Acyclic Graph) is the core concept of Airflow, collecting Tasks
together, organized with dependencies and relationships to say how they should
run. Using the Airflow Python script as a configuration file to specify the
DAG's structure as code.

An Airflow pipeline is just a Python script that happens to define an Airflow
DAG object.

## Declaring a DAG

1. Use a context manager, which add the DAG to anything inside it implicitly.
2. Use a standard constructor, passing the DAG into any operator you use.
3. Use the @dag decorator to turn a function into a DAG generator.

## Task Dependencies

A Task/Operator does not usually live alone, it has dependencies on other tasks,
and other tasks depend on it. Declaring these dependencies between task is what
make up the DAG structure.

```dag
first_task >> [second_task, third_task]
third_task << fourth_task

first_task.set_downstream(second_task, third_task)
third_task.set_upstream(fourth_task)

from airflow.models.baseoperator import cross_downstream
# Replaces
# [op1, op2] >> op3
# [op1, op2] >> op3

cross_downstream([op1, op2], [op3, op4])

# Replaces op1 >> op2 >> op3 >> op4
chain(op1, op2, op3, op4)

# You can also do it dynamically
chain(*[EmptyOperator(task_id='op' + i) for i in range(1, 6)])
```

## Loading DAGs

Airflow loads DAGs from python source files, which it looks for inside its
configured `DAG_FOLDER`. It will take each file, execute it, and then load any
DAG objects from that file. When Airflow comes to load DAGs from a Python file,
it will only pull any objects at the top level that are a DAG instance.
When searching for DAGs inside the DAG_FOLDER, Airflow only considers Python
files that contain the strings `airflow` and `dag` as an optimization.

## Running DAGs

DAGs will run in one of tow ways:

* When they are triggered either manually or via the API.
* On a defined schedule, which is defined as part of the DAG.

```python
with DAG("my_daily_dag", schedule="0 * * * *"):
```

## Control Flow

* Branching, where you can select which Task to move onto based on a condition.
* Latest Only, a special form of branching that only runs on DAGs running
  against the present.
* Depends On Past, where tasks can depend on themselves from a previous run.
* Trigger Rules, which let you set the conditions under which a DAG will run
  a task.

## DAG Visualization

* You can load up the Airflow UI, navigate to your DAG, and select "Graph
* You can run `airflow dags show`, which renders it our as an image file.

## TaskGroups

A TaskGroup can be used to organize tasks into hierarchical groups in Graph
view. It is useful for creating repeating patterns and cutting down visual
clutter.

By default, child tasks/TaskGroups have their IDs prefixed with the group_id of
their parent TaskGroup. This helps to ensure uniqueness of group_id throughout
the DAG.

## Edge Labels

You can label the dependency edges between different tasks in the Graph view,
this can be especially useful for branching area of your DAG, so you can label
the conditions under which certain branches might run.

```python
from airflow.utils.edgemodifier import Label

my_task >> Label("When empty") >> other_task
```
