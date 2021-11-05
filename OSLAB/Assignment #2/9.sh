echo -n "Size :"
read n
echo Enter Elements
i=0
while [ $i -lt $n ]
do
	read arr[$i]
	let i=i+1
done
echo Array :
echo ${arr[@]}
echo -n "Position to delete element (starts from 0) :"
read p
if [ $p -ge 0 -a $p -lt $n ];
then
	i=0
	while [ $i -lt $p ]
	do
		echo -n ${arr[$i]}
		echo -n " "
		let i=i+1
	done
	let i=i+1
	while [ $i -lt $n ]
	do
		echo -n ${arr[$i]}
		echo -n " "
		let i=i+1
	done
	echo ""
else
	echo "ERROR : Out of range"
fi	
