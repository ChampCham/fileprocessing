#!/bin/bash

extension=$1
dir=$2
file=$(ls $dir | grep -E -o "\w\.$extension")

for i in $file; do
	n=$(echo $i | cut -d '.' -f 1)
	mv $dir$i $dir$n
done
 

