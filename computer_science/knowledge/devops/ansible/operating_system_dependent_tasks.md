## Operating System Dependent Tasks
When working with multiple OSes, inevitably there will be packages, configuration files and service calls that are vastly different than one another. There can even be instances in which sub-versions of OSes can have major differences, such as `service` vs. `systemctl` in CentOS 6 vs. 7

### Task separation via Variables
This method pulls in variables based on the client's OS and uses those variables specific to that machine's needs.

A solution to this problem uses the Ansible module `include_vars` with the looping mechanism `with_first_found`.

```
- name: Load a variable file based on the OS type, or a default if not found. Using free-form to specify the file.
  include_vars: "{{ lookup('first_found', params) }}"
  vars:
    params:
      files:
        - '{{ansible_distribution}}.yaml'
        - '{{ansible_os_family}}.yaml'
        - default.yaml
      paths:
        - 'vars'
```


* [Operating System Dependent Tasks](https://ansible-tips-and-tricks.readthedocs.io/en/latest/os-dependent-tasks/variables/)
* [ansible.builtin.first_found – return first file found from list](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/first_found_lookup.html)
* [ansible.builtin.include_vars – Load variables from files, dynamically within a task](https://docs.ansible.com/ansible/latest/collections/ansible/builtin/include_vars_module.html)


