from encodings import utf_8
from tarfile import ENCODING
from PIL import Image
import cv2
import numpy as np
import sys

img_path = str(sys.argv[1])
tmp_path = str(sys.argv[2])

img = Image.open(img_path)
tmp = Image.open(tmp_path)
img_width, img_height = img.size
tmp_width, tmp_height = tmp.size
with open('dimensiones.txt', 'w') as fp:
    fp.write(str(img_width) + " " + str(img_height) + " ")
    fp.write(str(tmp_width) + " " + str(tmp_height))

img_array = cv2.imread(img_path, 0)
a_file = open("imagen.txt", "w")
np.savetxt('imagen.txt',img_array,fmt='%d')
img_array = cv2.imread(tmp_path, 0)
a_file = open("template.txt", "w")
np.savetxt('template.txt',img_array,fmt='%d')

a_file.close()