#!/bin/sh
make
echo "image path:"
read img_path
echo "template path:"
read tmp_path
echo "number of threads?:"
read threads
echo "getting matrix"
python3 imgProcessing.py $img_path $tmp_path
echo "getting dist matrix"
./main $threads
echo "locating template"
python3 locateTemplate.py $img_path