#! /bin/sh
#
# example.sh
# Copyright (C) 2021 shady <shady@MrRobot.local>
#
# Distributed under terms of the MIT license.
#


kubectl create deployment alpaca-prod \
    --image=gcr.io/kuar-demo/kuard-amd64:1 \
    --replicas=2 
kubectl label deployment alpaca-prod  ver=1 app=alpaca env=prod --overwrite



kubectl create deployment alpaca-test \
    --image=gcr.io/kuar-demo/kuard-amd64:2 \
    --replicas=1 
kubectl label deployment alpaca-test  ver=2 app=alpaca env=test --overwrite



kubectl create deployment bandicoot-prod \
    --image=gcr.io/kuar-demo/kuard-amd64:2 \
    --replicas=2 
kubectl label deployment bandicoot-prod  ver=2 app=bandicoot env=prod --overwrite



kubectl create deployment bandicoot-staging \
    --image=gcr.io/kuar-demo/kuard-amd64:2 \
    --replicas=1 
kubectl label deployment  bandicoot-staging  ver=2 app=bandicoot env=staging --overwrite
