echo "1.Number of presently active users\n2.Displaying some desired number of lines from top of a file\n3.Updating the access time of a given file to current time"
read x
case $x in
	1) echo -n "Active user(s) : "
	   w | tail +2 | wc -l;;
	2) echo "Enter file name :"
	   read f
	   if test -f "$f";
	   then
		   echo "No. of line(s) :"
		   read l
		   head -$l $f
	   else
		   echo "File not found!!!"
	   fi;;
	3) echo "Enter file name :"
           read ft
           if test -f "$ft";
	   then
		   touch "$ft"
		   ls -l "$ft"
	   else
		   echo "File not found!!!"
	   fi;;
	*) echo "Invalid Input!!!"
esac

