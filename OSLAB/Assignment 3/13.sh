echo -n String :
read str
len=${#str}
echo -n Substring :
read sub_str
sub_len=${#sub_str}
flag=0
if [ $sub_len -gt $len ];
then 
	echo Invalid Substring
else
	range=`expr $len - $sub_len + 1`
	i=0
	while [ $i -lt $range ]
	do
		if [[ ${str:$i:$sub_len} == $sub_str ]];
		then 
			echo "Position is $i (starting from 0th position)"
			flag=1
			break
		fi
		let i=i+1
	done
	if [ $flag -eq 0 ];
	then 
		echo Not found
	fi 
fi
 
