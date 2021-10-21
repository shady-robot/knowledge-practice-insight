from django.http import HttpResponse
from django.shortcuts import render
from django.db.models import Max
import json
import random

# Create your views here.

from .models import Pizza


def index(request, pid):
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
