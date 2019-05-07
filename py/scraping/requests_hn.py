import requests
import bs4  # Good for traversing html text 
from bs4 import BeautifulSoup as soup

my_url = 'https://news.ycombinator.com'
response = requests.get(my_url)
page_soup = soup(response.text, 'html.parser')
for container in page_soup.findAll('a', {'class':'storylink'}):
    print(container.href)

