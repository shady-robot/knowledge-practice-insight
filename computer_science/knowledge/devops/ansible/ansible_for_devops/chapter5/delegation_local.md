# Delegation and Local Actions

By default Ansible gathers facts and executes all tasks on the machines that
match the hosts line of your playbook. Ansible provide functionalities to
delegate tasks to a different machine or group, delegate facts to specific
machines or groups, or run an entire playbook locally. Using these approaches,
you can manage inter-related environments precisely and efficiently.

## Delegating tasks

If you want to perform a task on one host with reference to other hosts, use
the `delegate_to` keyword on a task.

```yaml
- name: Add server to munin monitoring configuration.
  command: monitor-sever webservers {{ inventory_hostname }}
  delegate_to: "{{ monitoring_master }}"

- name: Take out of load balancer pool
    ansible.builtin.command: /usr/bin/take_out_of_pool {{ inventory_hostname }}
    delegate_to: 127.0.0.1
- name: Take out of load balancer pool
  local_action: ansible.builtin.command /usr/bin/take_out_of_pool {{ inventory_hostname }}

- name: Recursively copy files from management server to target
  local_action: ansible.builtin.command rsync -a /path/to/files {{ inventory_hostname }}:/path/to/target/
```

## Local playbooks

It may be useful to use a playbook locally on a remote host, rather than by
connecting over SSH.

```yaml
$ ansible-playbook playbook.yml --connection=local

### Or make modification to your playbook
---
- hosts: 127.0.0.1
  connection: local
```

## Waits for a condition before continuing

use the `wait_for` to meed the conditions before continuing.

```yaml
- name: wait for web server to start.
  local_action:
    module: wait_for
    host: "{{ inventory_hostname }}"
    port: "{{ webserver_port }}"
    delay: 10
    timeout: 300
    state: started
```
