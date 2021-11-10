echo -n "Enter string :"
read str
if [ $(echo "$str" | rev) = $str ];
then
	echo Palindrome
else
	echo Not Palindrome
fi
