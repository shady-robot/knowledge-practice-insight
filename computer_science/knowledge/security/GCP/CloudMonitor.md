# Configuring and Using Cloud Logging and Cloud Monitoring

Logs with filtering mechanism, export logs to BigQuery syncs, and create logging metrics.

By default, the Cloud Logging retains log entries for 30 days. In most circumstances, you'll want to retain some log entries for an extended time and possible perform sophisticated reporting on the archived logs. Google Cloud provides a mechanism to have all log entries ingested into Cloud Monitoring also written to one ore more archival sinks.


## Cloud Audit Log

Cloud Audit Logs maintains two audit logs for each project and organization: Admin Activity and Data Access.

Data access audit logs(except for BigQuery) are disabled by default, so you must first enable all audit logs. Logging charges for the volume of log data that exceeds the free monthly logs allotment.


Admin Activity logs contain log entries for API calls or other administrative actions that modify the configuration or metadata of resources.
To view the logs, you must have the Cloud Identity and Access Management role Logging/Logs Viewer or Project/Viewer.



```sql
#standardSQL
SELECT
  timestamp,
  resource.labels.instance_id,
  protopayload_auditlog.authenticationInfo.principalEmail,
  protopayload_auditlog.resourceName,
  protopayload_auditlog.methodName
FROM
`auditlogs_dataset.cloudaudit_googleapis_com_activity_*`
WHERE
  PARSE_DATE('%Y%m%d', _TABLE_SUFFIX) BETWEEN
  DATE_SUB(CURRENT_DATE(), INTERVAL 7 DAY) AND
  CURRENT_DATE()
  AND resource.type = "gce_instance"
  AND operation.first IS TRUE
  AND protopayload_auditlog.methodName = "v1.compute.instances.delete"
ORDER BY
  timestamp,
  resource.labels.instance_id
LIMIT
  1000
```

Some example of gcloud commands:

```sh
gcloud compute instances create default-us-vm --zone=us-east1-c --network=mynetwork
gcloud compute instances delete --zone=us-east1-c --delete-disks=all default-us-vm
gsutil mb gs://$DEVSHELL_PROJECT_ID
gsutil mb gs://$DEVSHELL_PROJECT_ID-test
gsutil rm -r gs://$DEVSHELL_PROJECT_ID
gsutil rm -r gs://$DEVSHELL_PROJECT_ID-test
```


```sql
#standardSQL
SELECT
  timestamp,
  resource.labels.bucket_name,
  protopayload_auditlog.authenticationInfo.principalEmail,
  protopayload_auditlog.resourceName,
  protopayload_auditlog.methodName
FROM
`auditlogs_dataset.cloudaudit_googleapis_com_activity_*`
WHERE
  PARSE_DATE('%Y%m%d', _TABLE_SUFFIX) BETWEEN
  DATE_SUB(CURRENT_DATE(), INTERVAL 7 DAY) AND
  CURRENT_DATE()
  AND resource.type = "gcs_bucket"
  AND protopayload_auditlog.methodName = "storage.buckets.delete"
ORDER BY
  timestamp,
  resource.labels.instance_id
LIMIT
  1000
```