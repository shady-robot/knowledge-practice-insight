# Playbooks - intermediate

## Handlers

Handlers are tasks that only run when notified. Each handler should have a
globally unique name.

```yaml
handlers:
    - name: restart apache
      service: name=apache2 state=restarted

tasks:
    - name: Enable Apache rewrite module.
      apache2_module: name=rewrite state=present
      notify:
        - restart apache
        - restart memcached
```

By default, handlers run after all the tasks in a particular play have been
completed. If you need handlers to run before the end of the play, add a task
to flush them using the meta module.

```yaml
- name: Flush handlers
  meta: flush_handlers
```

## Environment variables

Refer to [environment variables](../../../linux/environment_variables.md).

Ansible allows you to work with environment variables in a variety of ways.

```yaml
- name: Add an environment variable to the remote user's shell
  lineinfile:
    dest: ~/.bash_profile
    regexp: '^ENV_VAR='
    line: "ENV_VAR=value"

- name: Get the value of the environment variable we just added.
  shell: 'source ~/.bash_profile && echo $ENV_VAR'
  register: foo

- name: Print the value of the environment variable.
  debug:
    msg: "The variable is {{ fo.stdout }}"
```

You can use the `environment` keyword at the play, block, or task level to
set an environment variable for an action on a remote host. The `environment`
keyword does not affect Ansible itself, Ansible configuration settings, the
environment for other users, or the execution of other plugins like lookups
and filters. Variables set with `environment:` do not automatically become
Ansible facts, even when you set them at the play level.

### Pre-task environment variables

You can use the environment keyword at the play, block, or task level to set
an environment variable for an action on a remote host.

```yaml
- hosts: all
  remote_user: root
  # create a variable named "proxy_env" that is a dictionary
  vars:
    proxy_env:
      http_proxy: http://proxy.example.com:8080

  tasks:
    - name: Install cobbler
      ansible.builtin.package:
        name: cobbler
        state: present
      environment: "{{ proxy_env }}"
```

You can persistent environment variables system-wide, by making changes to the
file `/etc/environment` using the following syntax.

```yaml
- name: Configure the proxy.
  lineinfile:
    dest: /etc/environment
    regexp: "{{ item.regexp }}"
    line: "{{ item.line }}"
    state: "{{ proxy_state }}"
  with_items:
    regexp: "^http_proxy="
    line: "http_proxy=http://example-proxy:80/"
    regexp: "^https_proxy="
    line: "https_proxy=https://example-proxy:443/"
    regexp: "^ftp_proxy="
    line: "ftp_proxy=http://example-proxy:80/"
```

refer to [EnvironmentVariables.yaml](./codes/environment.yaml) for demo.

## Other topics

### [Variables](./variables.md)

### [Conditionals](./conditionals.md)

### [Error Handling](./error_handling.md)

## References

* [environment variables](https://docs.ansible.com/ansible/latest/user_guide/playbooks_environment.html)
