#!/bin/bash

usage=$(du -m -s $1 | awk '{print $1}' )

if [ $usage -lt 1 ]; then
	echo "Low"
elif [ $usage -lt 10 ]; then
	echo "Medium"
else
	echo  "High"
fi

