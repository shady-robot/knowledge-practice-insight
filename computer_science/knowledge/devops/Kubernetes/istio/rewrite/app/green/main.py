from fastapi import FastAPI
from fastapi.openapi.docs import get_swagger_ui_html

app = FastAPI(
    title="Green Demo Service",
    description="This is a sample FastAPI service with Swagger documentation enabled.",
    version="1.0.0",
    # docs_url=None,  # Disable the default /docs route
    # redoc_url=None  # Disable the default /redoc route (optional)
)

# Serve OpenAPI JSON at a subpath
# @app.get("/openapi.json", include_in_schema=False)
# def custom_openapi():
#     return app.openapi()


# # Serve Swagger UI and point it to the custom OpenAPI JSON path
# @app.get("/docs", include_in_schema=False)
# def custom_swagger_ui():
#     return get_swagger_ui_html(openapi_url="/green/openapi.json", title=app.title)


@app.get("/", tags=["green"])
def read_root():
    """Root endpoint."""
    return {"message": "Welcome to the Green service!"}

@app.get("/health", tags=["green"])
def health_check():
    """Health check endpoint."""
    return {"status": "healthy", "service": "green"}

@app.get("/items/{item_id}", tags=["green"])
def read_item(item_id: int, q: str = None):
    """Retrieve an item by ID."""
    return {"item_id": item_id, "query": q}