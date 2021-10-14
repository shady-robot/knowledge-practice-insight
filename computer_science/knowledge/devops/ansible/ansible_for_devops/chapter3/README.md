# Ad-Hoc Commands

An Ansible ad hoc command uses the `/usr/bin/ansible` command-line tool to
automate a single task on one or more managed nodes. `ad hoc` commands are quick
and easy, but they are not reusable.

## Build infrastructure with Vagrant

![Multiple hosts](./images/multiple_hosts_vagrant.png)

Refer to [VagrantFile](./codes/Vagrantfile) for configuration.

## Configuring ansible

### Configuration file

Certain settings in Ansible are adjustable via a configuration file
`(ansible.cfg)`. The stock configuration should be sufficient for most users,
but there may be reasons you would want to change them.

```ini
[defaults]
inventory = hosts.ini
remote_user = root
private_key_file = ~/.ssh/id_rsa
host_key_checking = False
```

refer to [ansible default configuration][1] for more details.

### Environmental configuration

Ansible also allows configuration of settings using environment variables.
If these environment variables are set, they will override any setting
loaded from the configuration file.

```shellscript
export ANSIBLE_BECOME_ASK_PASS=false
```

## Inventory file

## ad-hoc command

```shell
ansible multi -a "hostname"
ansible multi -a "df -h"
ansible multi -a "date"
ansible multi -b -m yum -a "name=chrony state=present"
ansible db -b -m firewalld -a "zone=database state=present permanent=yes"
ansible multi -b -m cron -a "name='daily-cron-all-servers' \
hour=4 job='/path/to/daily-script.sh'"
```

## Ansible's SSH connection history

One of Ansible's greatest features is its ability to function without running
extra applications or daemons on the server is manages. Instead of using a
proprietary protocol to communicate with the servers, Ansible uses the
standard and secure SSH connection that is commonly used for basic
administration on almost every Linux server running today.

[1]:<https://github.com/ansible/ansible/blob/stable-2.11/examples/ansible.cfg>
