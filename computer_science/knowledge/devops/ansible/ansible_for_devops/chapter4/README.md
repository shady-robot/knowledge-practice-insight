# Ansible Playbooks

Playbooks record and execute Ansible’s configuration, deployment, and
orchestration functions. They can describe a policy you want your remote
systems to enforce, or a set of steps in a general IT process.

Playbooks may be included within other playbooks, and certain metadata and
options cause different plays or playbooks to be run in different scenarios
on different servers.

Refer to [demo.yaml](./codes/demo.yaml) for playbook demo.

## Specify hosts

```shell
# Limit a playbook to specific groups or individual hosts.
$ ansible-playbook demo.yaml --limit db
$ ansible-playbook playbook.yml --become --become-user=janedoe \
--ask-become-pass
```

If you want to see a list of hosts that would be affected by your playbook
before you actually run it, use `--list-hosts`

`$ansible-playbook playbook.yml --limit multi --list-hosts`

## Node App Example

Refer to [node](./codes/code) for node server project demo.

## References

* [ansible-examples](https://github.com/ansible/ansible-examples)