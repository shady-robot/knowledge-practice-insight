docker pull google/cloud-sdk:emulators
docker run --rm -p 8085:8085 google/cloud-sdk:emulators /bin/bash -c "gcloud beta emulators pubsub start --project=some-project-id --host-port='0.0.0.0:8085'"