# Error handling

When Ansible receives a non-zero return code from a command or a failure from a
module, by default it stops executing on that host and continues on other hosts.
However, in some circumstances you may want different behavior.Ansible provides
tools and settings to handle these situations and help you get the behavior,
output, and reporting you want.

## Ignoring failed commands

  The `ignore_errors` directive only works when the task is able to run and
  returns a value of ‘failed’. It does not make Ansible ignore undefined
  variable errors, connection failures, execution issues (for example,
  missing packages), or syntax errors.

## Defining failure

Ansible lets you define what “failure” means in each task using the
`failed_when` conditional. As with all conditionals in Ansible, lists of
multiple failed_when conditions are joined with an implicit `and`, or `or`.

```yaml
- name: Check if a file exists in temp and fail task if it does
  ansible.builtin.command: ls /tmp/this_should_not_be_here
  register: result
  failed_when:
    - result.rc == 0
    - '"No such" not in result.stdout'
```

## Defining "changed"

Ansible lets you define when a particular task has "changed" a remote node
using the `changed_when` conditional. This lets you determine, based on return
codes or output, whether a change should be reported in Ansible statistics and
whether a handler should be triggered or not.

```yaml
- name: Combine multiple conditions to override 'changed' result
  ansible.builtin.command: /bin/fake_command
  register: result
  ignore_errors: True
  changed_when:
    - '"ERROR" in result.stderr'
    - result.rc == 2
```

## Ensuring success for command and shell

The command and shell modules care about return codes, so if you have a command
whose successful exit code is not zero, you can do this:

```yaml
tasks:
  - name: Run this command and ignore the result
    ansible.builtin.shell: /usr/bin/somecommand || /bin/true
```
