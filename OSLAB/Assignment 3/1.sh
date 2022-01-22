echo "1.Merging the contents of two files into another\n2.Searching a pattern from a file"
read ch
case $ch in
	1) echo "Enter name of 2 files :"
	   read f1
	   read f2
	   if test -f "$f1" && test -f "$f2";
	   then
		   echo "Enter result file name :"
		   read f3
		   if test -f "$f3";
		   then
			   echo "$f3 already exixts!!!"
		   else
			   cat "$f1" "$f2" > "$f3"
			   cat "$f3"
		   fi
	   else
		   echo "Error finding file(s)"
	   fi;;
   	2) echo "Enter the pattern :"
	   read pat
	   echo "Enter file name :"
	   read f
	   if test -f "$f";
	   then
		   grep -h "$pat" "$f"
	   else
		   echo "File $f dosen't exist"
	   fi;;
	*) echo "Invalid Input!!!";;
esac

		 
