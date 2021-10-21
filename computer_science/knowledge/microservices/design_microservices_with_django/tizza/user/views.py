from django.shortcuts import render, redirect
from django.contrib import messages

from django.contrib.auth.forms import UserCreationForm

from django.contrib.auth import login, authenticate

# Create your views here.
from django.views import View

from .forms import UserLoginForm


class SignupView(View):
    template_name = "signup.html"

    def post(self, request):
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get("username")
            password = form.cleaned_data.get("password")
            user = authenticate(username=username, password=password)
            login(request, user)
            return redirect("register")

    def get(self, request):
        return render(request, self.template_name, {"form": UserCreationForm()})


class LoginView(View):

    template_name = "login.html"

    def post(self, request):
        form = UserLoginForm(request.POST)
        if form.is_valid():
            username = form.cleaned_data.get("username")
            password = form.cleaned_data.get("password")
            user = authenticate(username=username, password=password)
            login(request, user)
            return redirect("random_pizza")
        else:
            # print(form.non_field_errors)
            messages.error(request, message=form.errors)
            return redirect("login")

    def get(self, request):
        return render(request, self.template_name, {"form": UserLoginForm()})
