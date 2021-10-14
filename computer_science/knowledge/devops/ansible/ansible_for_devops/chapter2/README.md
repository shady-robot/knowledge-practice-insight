# Local Infrastructure Development

Prototyping and testing with local virtual machines.

Local development and testing of infrastructure is both safer and faster than
doing it on remote/live machine.

Vagrant, a server provisioning tool, and VirtualBox, a local virtualization
environment, make a potent combination for testing infrastructure and
individual server configurations locally.

## Vagrant

Vagrant is an open-source tool that allows you to create, configure, and
manage boxes of virtual machines through an easy to use command interface.

### vagrant box

The basic unit in a Vagrant setup is called a “box” or a “Vagrantbox.”
This is a complete, self-contained image of an operating system environment.

A Vagrant Box is a clone of a base operating system image. Using a clone
speeds up the launching and provisioning process.

```shell
$ vagrant box list
bento/ubuntu-16.04  (virtualbox, 201808.24.0)
bento/ubuntu-18.04  (virtualbox, 201812.27.0)
bento/ubuntu-20.04  (virtualbox, 202008.16.0)

$ vagrant box add bento/ubuntu-16.04
$ vagrant box remove bento/ubuntu-16.04
```

### vagrant operation

```shell
# The init command installs the box to the current directory and a Vagrantfile
# is placed in the same directory and can be edited or copied.

$ vagrant init bento/ubuntu-20.04

$ vagrant up
$ vagrant status
$ vagrant ssh
$ vagrant suspend
$ vagrant halt
$ vagrant destroy
```

refer [Vagrant/](./code) for vagrant provision.

### Functionality

* Network interface management

  In order to access the Vagrant environment created, Vagrant exposes some
  high-level networking options for things such as forwarded ports, connecting
  to a public network, or creating a private network.

  ```ruby
  Vagrant.configure("2") do |config|
    config.vm.network "forwarded_port", guest: 80, host: 8080
    config.vm.network "private_network", ip: "192.168.50.4"
  end
  ```

* Share folder management

  Synced folders enable Vagrant to sync a folder on the host machine to the
  guest machine, allowing you to continue working on your project's files on
  your host machine, but use the resources in the guest machine to compile or
  run your project.

  By default, Vagrant will share your project directory (the directory with the
  Vagrantfile) to /vagrant.

  ```ruby
    Vagrant.configure("2") do |config|
      # other config here

      config.vm.synced_folder "src/", "/srv/website"
    end
  ```

* Multi-machine management

  Vagrant is able to define and control multiple guest machines per
  Vagrantfile. These machines are generally able to work together or are
  somehow associated with each other.

  ```ruby
  Vagrant.configure("2") do |config|
    config.vm.provision "shell", inline: "echo Hello"

    config.vm.define "web" do |web|
      web.vm.box = "apache"
    end

    config.vm.define "db" do |db|
      db.vm.box = "mysql"
    end
  end
  ```

* Provisioning

  ```ruby
  config.vm.provision "ansible" do |ansible|
      ansible.playbook = "playbook.yml"
  end
  ```

## References

* [vagrant docs](https://www.vagrantup.com/docs/)
* [Vagrant Sync Directory](https://www.vagrantup.com/docs/synced-folders/basic_usage)