echo "Enter file name :"
read f
if test -f "$f";
then
	#wc -l "$f" | cut -d " " -f 1 
	echo "Starting line :"
	read st
	echo "No. of line(s) :"
	read n
	tail +$st $f | head -$n
else
	echo "File doesn't exist"
fi

