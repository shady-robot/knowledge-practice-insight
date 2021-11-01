#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
from django.urls import include, path
from .views import index, random_pizza

urlpatterns = [
    path("<int:pid>", index, name="pizza"),
    path("random", random_pizza, name="random_pizza"),
]
