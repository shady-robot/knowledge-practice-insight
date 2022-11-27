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

