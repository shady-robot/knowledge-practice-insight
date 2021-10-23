#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8

from django import forms
from django.contrib.auth import authenticate, get_user_model

User = get_user_model()


class UserLoginForm(forms.Form):
    username = forms.CharField(max_length=25)
    password = forms.CharField(widget=forms.PasswordInput)

    def clean(self, *args, **kwargs):
        username = self.cleaned_data.get("username")
        password = self.cleaned_data.get("password")
        user_qs_final = User.objects.filter(username__iexact=username).distinct()
        if not user_qs_final.exists() and user_qs_final.count() != 1:
            raise forms.ValidationError("Invalid credentials -- user not exist")
        user_obj = user_qs_final.first()
        if not user_obj.check_password(password):
            # log auth tries
            raise forms.ValidationError("Invalid credentials -- passowrd invalid")
        if not user_obj.is_active:
            raise forms.ValidationError(
                "Inactive user. Please verify your email address."
            )
        self.cleaned_data["user_obj"] = user_obj
        return super(UserLoginForm, self).clean(*args, **kwargs)
