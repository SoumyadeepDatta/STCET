echo -n 1st Num :
read a
echo -n 2nd Num :
read b
if [ $a -eq $b ];
then
	echo GCD is $a
elif [ $a -eq 0 ];
then
	echo GCD is $b
elif [ $b -eq 0 ];
then    
        echo GCD is $a
else
	while [ $a -ne $b ]
	do
		if [ $a -gt $b ];
		then
			a=`expr $a - $b`
		else
			b=`expr $b - $a`
		fi
	done
	echo GCD is $a
fi
