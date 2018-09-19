#!bin/bash

filename=$1
number=$(tail -n 1 $filename)
echo "$(($number + 1))" >> $filename
