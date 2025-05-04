from fastapi import FastAPI
from fastapi.openapi.docs import get_swagger_ui_html
from fastapi.openapi.utils import get_openapi
import httpx
import logging


logger = logging.getLogger('uvicorn.error')
logger.setLevel(logging.DEBUG)


app = FastAPI()

# List of services and their base paths
services = {
    "red": "http://red-service:8000",
    "green": "http://green-service:8000",
}

def get_unified_openapi():
    """Aggregate OpenAPI specs from all services."""
    openapi_docs = {}
    with httpx.Client() as client:
        for service_name, service_url in services.items():
            response = client.get(f"{service_url}/openapi.json")
            if response.status_code == 200:
                paths = response.json().get("paths", {})
                for item in paths:
                    path = f"/{service_name}{item}"
                    openapi_docs[path] = paths[item]
                openapi_docs[service_name] = response.json()
            else:
                logger.debug(f"{response.status_code} - {response.text}")   
    # Combine OpenAPI docs (you can customize this further)
    logger.debug("Combining OpenAPI docs")
    return openapi_docs


@app.get("/example")
def read_root():
    """Root endpoint."""
    logger.debug("Root endpoint called")
    return {"message": "Welcome to the Docs Aggregator service!"}

@app.get("/docs", include_in_schema=False)
async def unified_docs():
    """Serve Swagger UI for the unified OpenAPI."""
    logger.debug("Serving Swagger UI")
    return get_swagger_ui_html(openapi_url="/openapi.json", title="Unified API Docs")




def custom_openapi():
    if app.openapi_schema:
        return app.openapi_schema
    openapi_schema = get_openapi(
        title="Istio Aggregated API Docs",
        version="1.0.0",
        summary="Custom OpenAPI schema for Istio",
        description="Here's a longer description of the custom **OpenAPI** schema",
        routes=app.routes,
    )
    openapi_schema["info"]["x-logo"] = {
        "url": "https://fastapi.tiangolo.com/img/logo-margin/logo-teal.png"
    }
    logger.debug("Custom OpenAPI schema generated hell")
    aggreate_schema = get_unified_openapi()
    openapi_schema["paths"].update(aggreate_schema)
    app.openapi_schema = openapi_schema
    return app.openapi_schema


app.openapi = custom_openapi