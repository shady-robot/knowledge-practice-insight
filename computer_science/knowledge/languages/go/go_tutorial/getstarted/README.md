# Go - Hello World

## modules

When your code imports packages contained in other modules, you manage those
dependencies through your code's own module. This module is defined by a `go.mod`
file that tracks the modules that provide those packages. That `go.mod` file
stays with your code, including in your source code repository.

To enable dependency tracking for your code by creating a `go.mod` file, run the
`go mod init command`, giving it the same of the module your code will be in.
The name is the module's module path. In actual development, the module path will
typically be the repository location where your source code will be kept.

## go.mod file

The go.mod file is the root of dependency management in GoLang. All the modules
which are needed or to be used in the project are maintained in go.mod file.

Each Go module is defined by a `go.mod` file that describe the module's
properties, including its dependencies on other modules and on version of Go.

Go generates a `go.mod` file when you run the `go mod init command`. Use the
commands to manage dependencies. The commands ensure that the requirements
described in your go.mod file remain consistent and the content of your go.mod
file is valid.

### Properties

* The current module's **module path** This should be a location from which the
  module can be downloaded by Go tools, such as the module code's repository
  location. This serves as a unique identifier, when combined with the module's
  version number.
* The minimum version of Go required by the current module.
* A list of minimum version of other modules required by the current module.
* Instructions, optionally, to replace a required module with another module
  version or a local directory, or to exclude a specific version of a required
  module.

### mod file example

```mod
# Declares the module’s module path, which is the module’s unique identifier
module example.com/mymodule

# The minimum version of Go required to compile packages in this module.
go 1.14

# Declares a module as a dependency of the current module, specifying the
# minimum version of the module required.
require (
    example.com/othermodule v1.2.3
    example.com/thismodule v1.2.3
    example.com/thatmodule v1.2.3
)

# Replaces the content of a module at a specific version (or all versions) with
# another module version or with a local directory. Go tools will use the
# replacement path when resolving the dependency.

replace example.com/thatmodule => ../thatmodule

# Specifies a module or module version to exclude from the current module’s
# dependency graph.
exclude example.com/thismodule v1.3.0
```

## go.sum file

This file lists down the checksum of direct and indirect dependency required
along with the version. The checksum present in `go.sum` file is used to validate
the checksum of each of direct and indirect dependency to confirm that none of
them has been modified.

Ensure your `go.sum` file is committed along with your `go.mod` file. Refer to
[How to prepare for a release][1].

## Source Code

* [hello.go](./hello/hello.go)
* [external.go](./hello/external.go)

## References

* [go.mod file reference](https://golang.org/doc/modules/gomod-ref)
* [go modules](https://github.com/golang/go/wiki/Modules#should-i-commit-my-gosum-file-as-well-as-my-gomod-file)

[1]:<https://github.com/golang/go/wiki/Modules#should-i-commit-my-gosum-file-as-well-as-my-gomod-file>
