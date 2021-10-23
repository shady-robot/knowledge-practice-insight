from django.http import HttpResponse
from django.shortcuts import render
from django.db.models import Max
from django.contrib.auth.decorators import login_required
import json
import random

# Create your views here.

from .models import Pizza


@login_required
def index(request, pid):
    if request.method == "POST":
        data = json.loads(request.body)
        new_pizza = Pizza.objects.create(
            title=data["title"], description=data["description"], creator=request.user
        )
        new_pizza.save()
        data = {
            "id": new_pizza.pizza.id,
            "title": new_pizza.title,
            "description": new_pizza.description,
        }
        return HttpResponse(json.dumps(data), content_type="application/json",)
    elif request.method == "GET":
        try:
            pizza = Pizza.objects.get(id=pid)
            data = {
                "id": pizza.id,
                "title": pizza.title,
                "description": pizza.description,
            }
        except Pizza.DoesNotExist:
            data = {"status": "error", "message": "pizza not found"}
        return HttpResponse(json.dumps(data), content_type="application/json",)


def get_random():
    max_id = Pizza.objects.all().aggregate(max_id=Max("id"))["max_id"]
    while True:
        pk = random.randint(1, max_id)
        pizza = Pizza.objects.filter(id=pk).first()
        if pizza:
            return pizza


def random_pizza(request):
    pizza = get_random()
    data = {
        "id": pizza.id,
        "title": pizza.title,
        "description": pizza.description,
    }

    return HttpResponse(json.dumps(data), content_type="application/json",)
