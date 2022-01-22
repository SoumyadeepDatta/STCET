echo "No. of elements :"
read n
i=0
echo "Enter elements :"
while [ $i -lt $n ]
do
	read a[$i]
	i=`expr $i + 1`
done
min=${a[0]}
max=${a[0]}
j=0
while [ $j -lt $n ]
do
	if [ ${a[$j]} -gt $max ];
	then
		max=${a[$j]}
	fi
	if [ ${a[$j]} -lt $min ];
        then
                min=${a[$j]}
        fi
	j=`expr $j + 1`
done
echo "Max : $max"
echo "Min : $min"







