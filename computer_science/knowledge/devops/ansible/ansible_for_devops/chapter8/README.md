# Inventories

Ansible works against multiple managed nodes or “hosts” in your infrastructure
at the same time, using a list or group of lists known as inventory. Once your
inventory is defined, you use patterns to select the hosts or groups you want
Ansible to run against.

For typical team-managed infrastructure, it would be better to include an
inventory file for each environment in the same version-controlled repository
as your Ansible playbooks, perhaps within an `inventories` directory.

```shell
servercheck/
  inventories/
    inventory-prod
    inventory-cert
    inventory-dev
  playbook.yml
```

refer to [hosts.ini](./codes/hosts.ini) for demo.

## default groups

There are two default groups: `all` and `ungrouped`.

* `all`: contains every host.
* `ungrouped` contains all hosts that don't have another group aside from `all`

## Inveotry variables

Although you can store variables in the main inventory file, storing separate
host and group variables files may help you organize your variable value more
easily. By utilizing the `host_vars` and `group_vars` directory.

## Dynamic inventory

Ansible allows you to define inventory dynamically. If you're using one of the
larger cloud-based hosting providers, changes are there is already a dynamic
inventory script for you to use.

### Alicloud

[Managing ECS Instances with Ansible Dynamic Inventory](https://www.alibabacloud.com/blog/managing-ecs-instances-with-ansible-dynamic-inventory_594718)