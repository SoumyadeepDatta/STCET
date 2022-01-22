if test -f "$1";
then
	echo "$1 Exists"
else
	touch "$1"
fi
p= ls -l | grep -h "$1"
echo $p


