import os
from google.cloud import pubsub_v1
from google.api_core.exceptions import NotFound


project_id=os.getenv('GOOGLE_CLOUD_PROJECT')

publisher = pubsub_v1.PublisherClient()
topic_name='demo_example'


# List all topics for given project
project_path = f"projects/{project_id}"
topics = publisher.list_topics(request={"project": project_path}) 

# Check if topic exists, if not create the topic
topic_path = publisher.topic_path(project_id, topic_name)
print(topic_path)

try: 
    topic = publisher.get_topic(request={"topic": topic_path})
    print(f"Topic already exists: {topic.name}")
except NotFound:
    topic = publisher.create_topic(request={"name": topic_path})
    print(f"Topic created: {topic.name}")

future = publisher.publish(topic.name, b'My first message!', spam='eggs')
future.result()