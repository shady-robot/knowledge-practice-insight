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
