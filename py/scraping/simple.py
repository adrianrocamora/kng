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
print(len(containers))
print(containers[0].div.a.img["title"])
print(containers[0].findAll("a", {"class":"item-title"})[0].text)
print(containers[0].findAll("li", {"class":"price-ship"})[0].text.strip())

