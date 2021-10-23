from django.shortcuts import render, redirect
from django.contrib import messages

from django.contrib.auth.forms import UserCreationForm

from django.contrib.auth import login, authenticate, logout

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
        nxt = request.GET.get("next", None)
        print(nxt)
        if nxt is None:
            redirect_url = "random_pizza"
        else:
            redirect_url = nxt
        form = UserLoginForm(request.POST)
        if form.is_valid():
            username = form.cleaned_data.get("username")
            password = form.cleaned_data.get("password")
            user = authenticate(username=username, password=password)
            login(request, user)

            return redirect(redirect_url)
        else:
            # print(form.non_field_errors)
            messages.error(request, message=form.errors)
            return redirect("login")

    def get(self, request):
        return render(request, self.template_name, {"form": UserLoginForm()})


class LogoutView(View):
    def get(self, request):
        logout(request)
        return redirect("login")
