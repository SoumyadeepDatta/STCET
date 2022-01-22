echo -n "Enter number :"
read n
a=0
b=1
if [ $n -eq 0 ];
then
        echo $a
else
        echo $a
        while [ $b -le $n ]
        do
                t=$a
                a=$b
                b=`expr $t + $b`
                echo $a
        done
fi
      