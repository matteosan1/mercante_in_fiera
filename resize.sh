#! /bin/bash

for i in `ls *.png`
do
    convert -units PixelsPerInch $i -resample 150 -resize 177x291 -background white -gravity center -extent 177x291 resized_$i
done
#-resize 300x50 -background white -gravity center -extent 300x50 output.jpg
# 72dpi 188,268
