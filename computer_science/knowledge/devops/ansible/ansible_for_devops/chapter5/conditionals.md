# Conditionals

In a playbook, you may want to execute different tasks, or have different goals,
depending on the value of a fact (data about the remote system), a variable,
or the result of a previous task. You may want the value of some variables to
depend on the value of other variables. Or you may want to create additional
groups of hosts based on whether the hosts match other criteria. You can do all
of these things with conditionals.

Ansible uses `Jinja2 tests` and `filters` in conditionals. Ansible supports all
the standard tests and filters, and adds some unique ones as well.

```yaml
- name: Do something only for version 4 of the software.
 [task here]
  when: software_version.split('.')[0] == '4'
```

* `register`

  In Ansible, any play can 'register' a variable, and once registered, that
  variable will be available to all subsequent tasks. Registered facts are very
  helpful for many types of tasks, and can be used both with conditionals, and
  in any part of the play.

  ```yaml
  - name: Registered variable usage as a loop list
    hosts: all
    tasks:
    - name: Retrieve the list of home directories
      ansible.builtin.command: ls /home
      register: home_dirs

    - name: Add home dirs to the backup spooler
      ansible.builtin.file:
        path: /mnt/bkspool/{{ item }}
        src: /home/{{ item }}
        state: link
      loop: "{{ home_dirs.stdout_lines }}"
      # same as loop: "{{ home_dirs.stdout.split() }}"
  ```

* `when`

  ```yaml
  - yum: name=mysql-server state=present
    when: (is_db_server is defined) and is_db_server

  - name: Shut down CentOS 6 systems
    ansible.builtin.command: /sbin/shutdown -t now
    when:
      - ansible_facts['distribution'] == "CentOS"
      - ansible_facts['distribution_major_version'] == "6"

  # Includes let you re-use a file to define a variable when it is not
  # already defined
  - include_tasks: other_tasks.yml
    when: x is not defined

  ```
