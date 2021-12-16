# concepts

## Data model

Prometheus fundamentally stores all data as time series: streams of timestamped
values belonging to the same metric and the same set of labeled dimensions.
Besides stored time series, Prometheus may generate temporary derived time
series as the result of queries.

### Metrics names and labels

Every time series is uniquely identified by its metric name and optional
key-value pairs called labels. The metric name specifies the general feature of
a system that is measured.

Labels enable Prometheus's dimensional data model: any given combination of
labels for the same metric name identifies a particular dimensional
instantiation of that metric. For example,
`process_cpu_seconds_total{instance="localhost:9100",job="node"}`. The query
language allows filtering and aggregation based on these dimensions.

### Notation

Given a metric name and a set of labels, time series are frequently identified
using this notation:

```text
<metric name>{<label name>=<label value>, ...}

Example:
process_cpu_seconds_total{instance="localhost:9090",job="prometheus"}
process_cpu_seconds_total{instance="localhost:9100",job="node"}
```

## Metric types

The Prometheus client library offer four core metric types. There are currently
only differentiated in the client libraries(to enable APIs tailored to the usage
of the specific types) and in the wire protocol.

### Counter

A counter is cumulative metric that represents a single monotonically
**increasing** counter whose value can only increase or be reset to zero on
restart.

### Guage

A guage is a metric that represents a single numerical value that can
arbitrarily go up and down.

### Histogram

A histogram samples observations and counts them in configurable buckets. It
also provides a sum of all observed values.

A histogram with a base metric name of `<basename>` exposes multiple time series
during a scrape.

### Summary

A summary samples observations. While it also provide a total count of
observations and a sum of all observed values, it calculates configurable
quantiles over a sliding time window.

## Jobs and instances

In Prometheus, an endpoint you can scape is called an instance, usually
corresponding to a single process. A collection of instances with the same
purpose, a process replicated for scalability or reliability for example, is
called a job.

```text
job: api-server
    instance 1: 1.2.3.4:5670
    instance 2: 1.2.3.4:5671
    instance 3: 5.6.7.8:5670
    instance 4: 5.6.7.8:5671
```

When Prometheus scrapes a target, it attaches some labels automatically to the
scraped time series which serve to identify the scraped target.

* `job`: The configured job name that the target belongs to.
* `instance`: The `<host>:<port>` part of the target's URL that was scraped.
