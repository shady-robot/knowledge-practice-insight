# Google Cloud Pub/Sub

Google Cloud Pub/Sub is fully managed messaging service that empowers developers to build event-driven systems.

## Components

* Topics: Topics are named channels or categories to which message are sent by publishers.
* Subscriptions: Subscriptions are associated with specific topic and define where the messages should be delivered.
* Publishers: Publishers are entities that send messages to topics.
* Subscribers: Subscribers are entities that consume and process message from Pub/Sub topics.
* Messages: Messages are units of data or events sent by publishers to topics.

## Setting up Emulator locally

```sh
docker pull google/cloud-sdk:emulators
docker run --rm -p 8085:8085 google/cloud-sdk:emulators /bin/bash -c "gcloud beta emulators pubsub start --project=some-project-id --host-port='0.0.0.0:8085'"
```

## References

* [Python Github PubSub Example](https://github.com/googleapis/python-pubsub)