# ## Recipe API test

# This is the main document for experimenting with Recipe/Food/Plant APIs from Python 3

# Let's first try to query any simple open API using requests

import requests

# Let's try to get a response from the github API
response = requests.get('https://api.github.com')

# Let's get the status code for the response:
response.status_code

# Let's get the content for the response:
response.content

# Let's get the content for the response but as a string:
response.text

# Since the data is in json format, let's just get a dictionary directly:
response.json()

# Let's get the header info as a dictionary
response.headers

# Search GitHub's repositories for requests
response = requests.get(
    'https://api.github.com/search/repositories',
    params={'q': 'requests+language:python'},
)

# Let's get the status code for the response:
response.status_code

# Inspect some attributes of the `requests` repository
json_response = response.json();
repository = json_response['items'][0];
print(f'Repository name: {repository["name"]}')  # Python 3.6+
print(f'Repository description: {repository["description"]}')  # Python 3.6+

