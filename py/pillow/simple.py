# Create a new image

from PIL import Image, ImageDraw
img = Image.new('RGB', (800, 300), color='red')
img.save('/home/rocamora/wallpapers/wp.png')
