#!/bin/bash
currentYear=`date +"%Y"`
guest=$(cat $1)

for i in $guest; do
	echo $i | grep -E -o '(\d{4})\d{4}'
	yearBirth=\1
	age=$[currentYear - yearBirth] 
	if [ $age -ge 18 ]; then
		name=$(echo "$i" | cut -d ',' -f 1)
		surname=$(echo "$i" | cut -d ',' -f 2)
		echo "Dear Mr/Mrs $surname, $name"
	fi	
done
