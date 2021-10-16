# Environment variables

Environment variables provides a way to influence the behavior of software on
the system. Environment variables consist of names that have values assigned
to them.

## Manipulating environment variables and values

If we use an assignment expression for a variable that doesn't exist, the shell
will create a shell variable, which is similar to an environment variable but
does not influence the behavior of other applications.

A shell variable can be exported to become an environment variable with the
export command.

```shell
LANG=he_IL.UTF-8

export EDITOR=vim
```

To examine the environment or erase the variable.

```shell
printenv | grep NAME
echo $TERM
env

# erasing the variables
unset LC_ALL
```

## Working principles

* Process locality
    The value of environment variables are local, which means they
    are specific to the running process in or for which they were
    set.
* Inheritance
    When a parent process creates a child process, the child process inherits
    all the environment variables and the value the parent process had.
* Case sensitivity
    The names of environment are case sensitive. It is common practice to name
    all environment variables with only English capital letters and
    underscore(_) sign.

## Persistent environment variables

### Session-wide environment variables

Suitable files for environment variable settings that should affect just
a particular user.

```shell
~/.profile
~/.bashrc
 ~/.bash_profile
```

### System-wide environment variables

A suitable file for environment variable settings that affect the system as a
whole (rather than just a particular user) is `/etc/environment`. An alternative
is to create a file for the purpose in the `/etc/profile.d` directory.

`/etc/environment` This file is specifically meant for system-wide environment
variable settings. It is not a script file, but rather consists of assignment
expressions, one per line. It's pure key-value pairs, with values optionally
quoted. You can't put anything that tries to do e.g. variable expansion or
command execution in there and expect it to work.

## References

* [EnvironmentVariables](https://help.ubuntu.com/community/EnvironmentVariables)