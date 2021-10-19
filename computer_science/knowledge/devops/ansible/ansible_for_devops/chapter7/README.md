# Ansible Plugin and content collections

Distribute Ansible plugins-Python code to extend Ansible's functionality with
new modules, filters, inventory plugins, and more.

Collections allow the gathering of Ansible plugins, roles, and even playbooks
into one entity, in a more structured way that Ansible, Ansible Galaxy, and
Automation Hub can scan and consume.

## A Jinjia filter

Filter plugins allow you to verify data, and are some of the simpler types of
plugins you'll find in Ansible.

```python
class TestModule(object):
    """Return dict of custom Jinjia tests. """
    def tests(self):
        return {
            'blue': is_blue
        }
```

Ansible calls the tests method in this class in any Python file inside the
`test_plugins` directory, and loads any of the returned keys as available
Jinjia tests.

## Content Collections

Collections are a distribution format for Ansible content that can include
playbooks, roles, modules, and plugins.

Ansible core repository will still hold a few foundational plugins and
modules, vendor-supported and Red Hat-supported modules will be split out into
their own collections, and community modules will be in their own collections.

`ansible-galaxy collection init local.colors --init-path ./collections\
/ansible_collections`

`./collections/ansible_collections` is required so Ansible can use Python's
built-in namespace-based loader to load content from the collection.

* To install a collection hosted in Galaxy.

  `ansible-galaxy collection install my_namespace.my_collection`
* To upgrade a collection to the latest available version.

  `ansible-galaxy collection install my_namespace.my_collection --upgrade`
* Using a `requirements.yaml` file.

  `ansible-galaxy install -r requirementx.yaml`
