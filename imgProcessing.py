from PIL import Image
import cv2
import numpy as np

im = Image.open('test.png')
width, height = im.size
dimensions = (width,height)

img_path = 'test.png'
img = cv2.imread(img_path, 0)
img.astype('int16').tofile('imgMatrix')