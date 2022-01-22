read num
temp=`expr $num % 2`
if [ $temp -eq 0 ];
then
	echo "EVEN"
else
	echo "ODD"
fi


