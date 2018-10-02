#!/bin/bash
curl -s  https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw > tmp.txt
file=tmp.txt

countries=$(cat  $file | grep -E -o '[0-9]{1,2}\|\|{{flag\|[A-Za-z]+')
count=0
for i in $countries; do
	country=$(echo "$i" | grep -E -o '\b[A-Za-z]+$' )
	echo "$country"
	count=$[count+1]
	if [ $count -eq 10 ];then 
		break 
	fi	
done
rm tmp.txt






