from selenium import webdriver
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.keys import Keys

opts = Options()
opts.set_headless()
assert(opts.headless) # Operating in headless mode
driver = webdriver.Firefox(options=opts)
driver.get("http://www.python.org")
assert("Python" in driver.title)
elem = driver.find_element_by_name("q")
elem.clear()
elem.send_keys("pycon")
elem.send_keys(Keys.RETURN)
assert( "No results found." not in driver.page_source)
print(driver.page_source)
driver.close()
print('Great Success')
