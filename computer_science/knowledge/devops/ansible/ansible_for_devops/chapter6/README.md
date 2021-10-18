# Playbook organization

Ansible is flexible when it comes to organizing task in more efficient ways so
you can make playbooks more maintainable, reusable, and powerful.

## import

Importing roles, tasks, or playbooks adds them to a playbook statically.
Ansible pre-processes imported files and roles before it runs any tasks in a
playbook, so imported content is never affected by other tasks within the
top-level playbook.

```yaml
tasks:
  - import tasks: imported-tasks.yml
    vars:
      wp_user: bob
```

## includes

Include roles, tasks, or variables adds them to a playbook dynamically.

If you use `import_tasks`, Ansible statically imports the task file as if it
were part of the main playbook, once, before the Ansible play is executed.

If you need to have included tasks that are dynamic - that is, they need to
do different things depending on how the rest of the playbook runs - then you
use `include_tasks` rather than `import_tasks`.

### dynamic includes

```yaml
- name: Check if extra_tasks.yml is present.
  stat:
    path: tasks/extra-tasks.yml
  register: extra_tasks_file
  connection: local

- include_tasks: tasks/extra-tasks.yml
  when: extra_tasks_file.exists

- name: Inlcude OS-specific variables.
  include_vars: "{{ ansible_os_family }}.yml"

- name: Include OS-specific setup tasks.
  include_tasks: setup-{{ ansible_os_family }}.yml

- name: Other OS-agnostic tasks...
```

### playbook imports

Playbooks can even be included in other playbooks, using the same import
syntax in the top level of your playbook.

```yaml
- hosts: all
  remote_user: root
  tasks:
    [...]
- import_playbook: web.yml
- import_playbook: db.yml
```

## Roles

Ansible roles are powerful and flexible, they allow you to encapsulate sets of
configuration and deployable units of playbooks, variables, templates, and
other files, so you can easily reuse them across different servers.

Using the following command to build the scaffolding for a role.
`ansible-galaxy role init role_name`

```text
ansible-role-demo
├── README.md
├── defaults
│   └── main.yml
├── files
├── handlers
│   └── main.yml
├── meta
│   └── main.yml
├── tasks
│   └── main.yml
├── templates
├── tests
│   ├── inventory
│   └── test.yml
└── vars
    └── main.yml
```

When running a role's tasks, Ansible picks up variables defined in a role's
`vars/main.yml` file and `defaults/main.yml`, but will allow your playbooks to
override the defaults or other role-provided variables if you want.

```yaml
---
- hosts: webservers
  roles:
    - common
    - role: foo_app_instance
      vars:
        dir: '/opt/b'
        app_port: 500
      tags: typeB

   tasks:
    - name: Inlcude the example role
      include_role:
        name: example
```

## Ansible Galaxy

Ansible Galaxy, is a repository of community-contributed Ansible content.
Galaxy offers the ability to add, download, and rate roles.

```yaml
ansible-galaxy role install geerlingguy.apache
```

`ansible-galaxy install -r requirements.yml`
Multiple roles can be installed by listing them in a requirements.yml file.
The format of the file is `YAML`, and the file extension must be either `.yml`
or `.yaml`. Each role in the file will have one or more of the following
attributes:

* src: The source of the role, and a required attribute.
* scm: If the src is a URL, specify the SCM.
* version: The version of the role to download.
* name: Download the role to a specific name.

refer to [requirements.yml](./codes/requirements.yml) for demo.

### Helpful Galaxy comamnds

```shell
ansible-galaxy role list
ansible-galaxy role add
ansible-galaxy role remove
ansible-galaxy role init
```
