# PromQL

PromQL is the querying language that is part of Prometheus. Prometheus provides
a scraper that fetches metrics from instances and a time series database(TSDB),
which store these metrics over time.

## Prometheus

Prometheus uses a pull model, and the metric collection process is called
scraping.

In Prometheus, scraping is configured via providing a static list of
`<host>:<port>` scraping targets. It's also possible to configure a
service-discovery-specific(consul, docker, kubernetes, ec2, etc.) endpoint to
fetch such a list at runtime.

In general, a stream of timestamped value is called a time series. A time series
in Prometheus is defined by a combination of a metric name and a particular set
of key-value labels.

Values are always floating-point numbers, timestamps are integers storing the
number of milliseconds since the Unix epoch.

## PromQL binary operators

PromQL comes with 15 binary operators that can be divided into three groups by
operation type:

* arithmetic `+ - / * ^ %`
* comparison `< > <= >= == !=`
* logical/set `and, unless, or`

Binary operations are defined for different types of operands - scalar/scalar,
scalar/vector, and vector/vector. And the last pair of operands, vector/vector,
is the most puzzling one because the subtle vector matching rules may differ
depending on the cardinality of the sides or operation type.

## Expression language data types

In Prometheus's expression language, an expression or sub-expression can
evaluate to one of four types.

* Instant vector - a set of time series containing a single sample for each time
  series, all sharing the same timestamp.
* Range vector - a set of time series containing a range of data points over for
  each time series.
* Scalar - a simple numeric floating point value.
* String - a simple string value, currently unused.

refer to [PromQL for Human][1].

## References

* [PromQL for Human][1]

[1]:<https://timber.io/blog/promql-for-humans/>
