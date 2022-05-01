#!/bin/sh
echo "image path:"
read img_path
echo "template path:"
read tmp_path
echo "getting matrix"
python3 imgProcessing.py $img_path $tmp_path
echo "getting dist matrix"
./main
echo "locating template"
python3 locateTemplate.py $img_path