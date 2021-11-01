#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8

from django.urls import path
from .views import SignupView, LoginView, LogoutView

urlpatterns = [
    path("register", SignupView.as_view(), name="register"),
    path("login", LoginView.as_view(), name="login"),
    path("logout", LogoutView.as_view(), name="logout"),
]
