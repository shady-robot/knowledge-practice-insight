@task.branch(task_id="branch_task")
def branch_func(ti):
    xcom_value = int(ti.xcom_pull(task_ids="start_task"))
    if xcom_value >= 5:
        return "continue_task"
    elif xcom_value >= 3:
        return "stop_task"
    else:
        return None
start_op = BashOperator(
    task_id="start_task",
    bash_command="echo 5",
    xcom_push=True,
    dag=dag,
)

branch_op = branch_func()

continue_op = EmptyOperator(task_id="continue_task", dag=dag)
stop_op = EmptyOperator(task_id="stop_task", dag=dag)
start_op >> branch_op >> [continue_op, stop_op]