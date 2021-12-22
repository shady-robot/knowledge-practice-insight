# Monitoring Distributed Systems

## Definitions

* Monitoring
    Collecting, processing, aggregating, and displaying real-time quantitative
    data about a system, such as query counts and bytes, error counts and types,
    processing times, and server lifetimes.
* Block-box monitoring
    Testing externally visible behavior as a user would see it.
* White-box monitoring
    Monitoring based on metrics exposed by the internals of the systems,
    including logs, interfaces like the Java Virtual Machine Profiling Interface
    ,or an HTTP handler that emits internal statistics.
* Root cause
    A defect in a software or human system that, if repaired, installs
    confidence that this event won't happen again in the same way.

## Why monitoring

* 长期趋势分析：通过对监控样本数据的持续收集和统计，对监控指标进行长期趋势分析。例如，通过对磁盘
  空间增长率的判断，我们可以提前预测在未来什么时间节点上需要对资源进行扩容。
* 对照分析：两个版本的系统运行资源使用情况的差异如何？在不同容量情况下系统的并发和负载变化如何?
  通过监控能够方便的对系统进行跟踪和比较。
* 告警：当系统出现或者即将出现故障时，监控系统需要迅速反应并通知管理员，从而能够对问题进行快速的
  处理或者提前预防问题的发生，避免出现对业务的影响。
* 故障分析与定位：当问题发生后，需要对问题进行调查和处理。通过对不同监控监控以及历史数据的分析,
  能够找到并解决根源问题。
* 数据可视化：通过可视化仪表盘能够直接获取系统的运行状态、资源使用情况、以及服务运行状态等直观的
  信息。

## Rules

* Keep noise low and signal high.
* Rules that generate alerts for human should be simple to understand and
  represent a clear failure.
* Paging a human is a quite expensive use of an employee's time. Effective
  alerting systems have good signal and very low noise.

## Setting reasonable expectations for monitoring

In general, Google has trended toward simpler and faster monitoring systems,
with better tools for post hoc analysis.

It's important that monitoring systems - especially the critical path from the
onset of a production problem, through a page to a human, through basic triage
and deep debugging - be kept simple and comprehensible by everyone on the team.

## Symptoms versus Causes

Your monitoring system should address two questions: what's broken, and why?

## Black-Box versus White-Box

We combine heavy use of white-box monitoring with modest but critical used of
black-box monitoring.

* Black-box monitoring is symptom-oriented and represent active - no predicted
  problems.
* White-box monitoring depends on the ability to inspect the innards of the
  system, which allows detection of imminent problems, failures masked by
  retries, and so forth.

## The four golden signals

### Latency

The time it takes to service a request. It's important to distinguish between
the latency of a successful requests and the latency of failed requests.

### Traffic

A measure of how much demand is being placed on your system, measured in a
high-level system specific metric.

### Errors

The rate of request that fail, either explicitly, implicitly, or by policy.

### Saturation

How "full" your service is. A measure of your system fraction, emphasizing the
resources that are most constrained.
