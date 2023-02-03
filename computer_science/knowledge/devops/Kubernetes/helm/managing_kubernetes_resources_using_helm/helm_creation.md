# Helm Chart Developer

## Scaffolding a New Helm Chart

```shell
$ helm create guestbook
Creating guestbook

$ tree

-- guestbook
    |-- charts                  -- dependencies
    |-- Chart.yaml              -- metadata about the Helm chart
    |-- templates               -- Golang templates, used for generating k8s
    |   |                           resources
    |   |-- deployment.yaml     -- *.yaml template file to geneate k8s resources
    |   |-- _helpers.tpl        -- boilerplate helper templates
    |   |-- hpa.yaml
    |   |-- ingress.yaml
    |   |-- NOTES.txt
    |   |-- serviceaccount.yaml
    |   |-- service.yaml
    |   `-- tests
    |       `-- test-connection.yaml
    `-- values.yaml             -- contains the chart's default values
```

## Helm Dependencies

Chart dependencies are used to install another chart's resources that a Helm
chart(referred to as the parent chart) may depend on.

### Helm Dependencies Fields

| Field  | Description   |
|---|---|
|  Name  | The name of the dependency chart  |
|  Repository | The location where the dependency chart resides   |
|  Version | The chart dependency version |
|  Condition | A Boolean value that determines whether the dependency should be included or not|
|  Tags | A list of Boolean values determine whether the chart should be included or not |
|  import-values | A mapping of source values to parent values |
|  Alias | An alternative name to give the dependency |

### Manage Helm Dependencies

Chart dependencies can be viewed and downloaded using the `helm dependency`.

The `Chart.lock` file is generated upon running `helm dependency update`, and it
contains a list of dependencies. The file is used to lock in the dependency
versions so that the same versions can be downloaded on other machines.

```shell
helm dependency list  # List the dependencies for the given charts
helm dependency update # Downloads the dependencies listed in `Charts.yaml` and
                       # generates a `Charts.lock` file
helm dependency build # Download the dependencies listed in `Chart.lock`.
```

### Conditions

Conditional dependencies can be created by using the condition and tags fields
of the dependencies map. The `condition` field is used to list `Boolean` values
that, if present, toggle the inclusion of the dependency.
The `condition` is best used for enabling individual dependencies using the
`chartname.enabled` format, `tags` is used to enable or disable one or more
dependencies by associating each dependency with descriptive labels.

```shell
$ helm upgrade conditional-example chapter5/examples/tags-example
    --set tags.backend=false --set tags.database=true –n chapter5
$ helm get manifest conditional-example –n chapter5 | grep mariadb
```

## Templates

Helm templates are used to dynamically generate Kubernetes YAML resources. They
consume a set of default and user-provided values to generate resources that
comprise a Kubernetes application.

Helm templates contain various different actions, or strings, that begin with
two opening curly brace ({{) and end with accompanying two closing curly brace
(}}). Actions mark locations where data processing occurs or where control
structures such as conditionals and loops are implemented.

The `helm template` is used to render template resources locally, but not
install them to the Kubernetes clusters.

`helm template <RELEASE_NAME> <CHART_NAME> [flags]`

### Built-in objects

Built-in objects are essential building blocks that you can used to write your
own Helm charts.

| Object  | Definition  |
|---|---|
| .Values  | Used to access values in the `value.yaml` file or values that were provided using the --valued and --set flags  |
| .Release  | Used to access metadata about the Helm release  |
| .Chart | Used to access metadata about the Helm chart |
| .Template | Used to access metadata about chart templates |
| .Capabilities | Used to access information about the Kubernetes cluster |
| .File | Used to access arbitrary files within a Helm chart directory |
| . | The root object |

#### The Release object

Release is one of the top-level objects that you can access in your templates.
Release: This object describes the release itself. It has several objects inside
of it:

* Release.Name: The release name
* Release.Namespace: The namespace to be released into
* Release.IsUpgrade: This is set to true if the current operation is an
  upgrade or rollback.
* Release.IsInstall: This is set to true id the current operation is an install
* Release.Revision: The revision number for this release.
* Release.Service: The service that is rendering the present template.

Refer to [Helm Objects](https://helm.sh/docs/chart_template_guide/builtin_objects/#helm).
