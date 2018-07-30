#!/bin/bash

for size in `seq 5000 5000 100000`
do
	echo "Testing size: $size"
	./randl "$size" > nums.txt
	time ./usel < nums.txt > /dev/null
done