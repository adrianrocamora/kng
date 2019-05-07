import bs4  # Good for traversing html text 
from urllib.request import urlopen

my_url = 'https://news.ycombinator.com'
uclient = urlopen(my_url)
page_html = uclient.read()
uclient.close()

page_soup = bs4.BeautifulSoup(page_html, "html.parser")
#print(page_soup.prettify())
tds = page_soup.findAll('a')
print(len(tds))
print(tds[0].a)


# containers = page_soup.findAll("div", {"class": "item-info"})

# filename = 'newegg_gpus.csv'
# f = open(filename, 'w')
# headers = 'brand, product_name, shipping'
# f.write(headers)

# for container in containers:
	# brand = container.div.a.img["title"]
	# product_name = container.findAll("a", {"class":"item-title"})[0].text
	# shipping = container.findAll("li", {"class":"price-ship"})[0].text.strip()

	# print(brand)
	# print(product_name)
	# print(shipping)
	# print('')

	# f.write(brand + ',' + product_name.replace(',', '|') + ',' + shipping + '\n')
# f.close()

