echo "Enter num :"
read num
t=$num
temp=$num
c=0
while [ $t -gt 0 ]
do
    t=`expr $t / 10`
    c=`expr $c + 1`
done
sum=0
while [ $temp -gt 0 ]
do
    digit=`expr $temp % 10`
    add=$(($digit**$c))
    sum=`expr $sum + $add`
    temp=`expr $temp / 10`
done
if [ $sum -eq $num ];
then
    echo "Armstrong"
else
    echo "Not Armstrong"
fi
