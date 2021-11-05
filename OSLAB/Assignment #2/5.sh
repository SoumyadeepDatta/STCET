echo -n Provide filename :
read fname
if test -f "$fname";
then
	echo File already exists...
else
	touch $fname
	echo -n Total Numbers :
	read n
	i=0
	echo Enter numbers :
	while [ $i -lt $n ]
	do
		read arr[$i]
		echo ${arr[$i]} >> "$fname"
		let i=i+1
	done
	echo Sorting in descending order...
	sort -nr "$fname"
	rm "$fname"
fi 
