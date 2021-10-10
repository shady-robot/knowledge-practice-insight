# Discovering variables: facts and magic variables

With Ansible you can retrieve or discover certain variables containing
information about your remote systems or about Ansible itself.

* **facts**: Variables related to remote systems are called facts.
* **magic variables**: Variables related to Ansible are called magic variables.

## Ansible facts

Ansible facts are data related to your remote systems, including operating
systems, IP addresses, attached filesystems, and more.

* Access data in the `ansible_facts` varaible.
* Access some Ansible facts as top-level varaibles with the `ansible_` prefix.

```yaml
- hosts: whatever
  gather_facts: no
```
