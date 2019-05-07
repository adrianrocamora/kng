import bs4  # Good for traversing html text 
from urllib.request import urlopen as uReq
from bs4 import BeautifulSoup as soup

my_url = 'https://www.newegg.com/Video-Cards-Video-Devices/Category/ID-38'
#print(my_url)
uClient = uReq(my_url)
page_html = uClient.read()
#print(page_html)
uClient.close()

page_soup = soup(page_html, "html.parser")

containers = page_soup.findAll("div", {"class": "item-info"})

for container in containers:
	brand = container.div.a.img["title"]
	product_name = container.findAll("a", {"class":"item-title"})[0].text
	shipping = container.findAll("li", {"class":"price-ship"})[0].text.strip()

	print(brand)
	print(product_name)
	print(shipping)
	print('')
