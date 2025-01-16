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

Google Cloud Pub/Sub is a fully-managed real-time messaging service that allows you to send and receive message between independent applications. You can leverage Cloud Pub/Sub's flexibility to decouple systems and components hosted on Google Cloud
platform or elsewhere on the Internet.


## References

* [Python Github PubSub Example](https://github.com/googleapis/python-pubsub)
* [pubsub-emulator-ui](https://github.com/NeoScript/pubsub-emulator-ui)
* [Google Cloud Pub/Sub Python Documentation](https://cloud.google.com/pubsub/docs/list-topics#pubsub_list_topics-python)