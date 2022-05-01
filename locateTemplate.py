import cv2
import sys
 
img_path = str(sys.argv[1])
img = cv2.imread(img_path)
f = open('output.txt','r')
lines = f.readlines()
x=int(lines[0])
y=int(lines[1])
xdim=int(lines[2])
ydim=int(lines[3])
cv2.rectangle(img, (x, y), (x+xdim, y+ydim), (0, 255, 0),-1)
res = cv2.resize(img, dsize=(500,500), interpolation=cv2.INTER_CUBIC)
cv2.namedWindow("imagen", cv2.WINDOW_NORMAL)
cv2.imshow("imagen", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
