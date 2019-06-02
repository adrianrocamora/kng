# Create a new image from two images

import os
import random

from PIL import Image, ImageDraw
img = Image.new('RGB', (1400, 800), color='blue')
img.save('/home/rocamora/wallpapers/wp.png')

path = '/home/rocamora/wallpapers/x'

files = []
# r=root, d=directories, f = files
for r, d, f in os.walk(path):
    for file in f:
        if '.jpg' or '.png' or '.jpeg' in file:
            files.append(os.path.join(r, file))

random_choices = random.sample(files, k=2)
print(random_choices)



