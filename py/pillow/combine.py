# Create a new image from two images
import os
import random

panel_w = 700
panel_h = 1000

from PIL import Image, ImageDraw
img_wp = Image.new('RGB', (panel_w*2, panel_h), color='black')

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
img_left.thumbnail((panel_w, panel_h))
img_right = Image.open(random_choices[1])
img_right.thumbnail((panel_w, panel_h))

img_left_x0 = 0 + (panel_w - img_left.width)//2
img_left_y0 = 0 + (panel_h - img_left.height)//2

img_right_y0 = 0 + (panel_h - img_right.height)//2
img_right_x0 = panel_w + (panel_w - img_right.width)//2

img_wp.paste(img_left, (img_left_x0, img_left_y0))
img_wp.paste(img_right, (img_right_x0, img_right_y0))

img_wp.save('/home/rocamora/wallpapers/wp.png')



# #Iterate through a 4 by 4 grid with 100 spacing, to place my image
# for i in range(0,1400,700):
    # for j in range(0,1400,700):
        # #I change brightness of the images, just to emphasise they are unique copies.
        # #img_wp = Image.eval(im,lambda x: x+(i+j)/30)
        # #paste the image at location i,j:
        # img_wp.paste(im, (i,j))
