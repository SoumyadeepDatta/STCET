echo -n "Number :"
read n
t=1
i=1
while [ $i -le $n ]
do
	t=`expr $t \* $i`
	i=`expr $i + 1`
done
echo $t

