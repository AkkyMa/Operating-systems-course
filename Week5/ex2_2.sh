#!bin/bash

filename=$1
lockname=$filename".lock"
while true
do
	if ln $filename $lockname
	then
		number=$(tail -n 1 $filename)
		echo "$(($number + 1))" >> $filename
		rm $lockname
		break
	fi
done
