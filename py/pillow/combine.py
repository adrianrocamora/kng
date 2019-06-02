# Create a new image from two images

import os
import random

from PIL import Image, ImageDraw
img_wp = Image.new('RGB', (1400, 1000), color='black')

path = '/home/rocamora/wallpapers/x'

files = []
# r=root, d=directories, f = files
for r, d, f in os.walk(path):
    for file in f:
        if '.jpg' or '.png' in file:
            files.append(os.path.join(r, file))

random_choices = random.sample(files, k=2)
print(random_choices)

img_left = Image.open(random_choices[0])
img_left.thumbnail((700, 1000))
img_right = Image.open(random_choices[1])
img_right.thumbnail((700, 1000))

# #Iterate through a 4 by 4 grid with 100 spacing, to place my image
# for i in range(0,1400,700):
    # for j in range(0,1400,700):
        # #I change brightness of the images, just to emphasise they are unique copies.
        # #img_wp = Image.eval(im,lambda x: x+(i+j)/30)
        # #paste the image at location i,j:
        # img_wp.paste(im, (i,j))

print(img_left.width)
img_wp.paste(img_left, (0,0))
img_wp.paste(img_right, (700,0))

img_wp.save('/home/rocamora/wallpapers/wp.png')
