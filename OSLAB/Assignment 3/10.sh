i="y"
echo "Enter name of the file "
read -r file
if [[ ! -e $file ]]; then
    touch "$file"
    echo "ROLL NUMBER | NAME | CITY" >>"$file"

fi

while [ $i = "y" ]; do
    echo "1.Display the contents of whole file"
    echo "2.Display the information of a student with specific Roll Number supplied by the User"
    echo "3.Add a new entry in the file"
    echo "4.Delete the entry of a student from the file with a specific Roll Number supplied by User"
    echo "5.Update an entry of a student with a specific Roll Number supplied by the User"
    echo "6.Exit"
    echo "Enter your choice "
    read ch
    case $ch in
    1) sort -n -k 1 "$file" ;;
    2)
        echo "Enter Roll Number"
        read roll
        grep -i "$roll" "$file"
        ;;
    3)
        echo "Enter Roll Number: "
        read roll
        echo "Enter new Student name: "
        read name
        echo "Enter City: "
        read city
        echo "$roll | $name | $city" >>"$file"
        ;;
    4)
        echo "Enter Roll Number"
        read roll
        record=$(grep -v "$roll" "$file")
        echo "$record" >"$file"
        echo "Entry is deleted"
        cat "$file"
        ;;
    5)
        echo "Enter Roll No of the student to update"
        read roll
        record=$(grep -v "$roll" "$file")
        echo "$record" >"$file"
        echo "Enter new Student name: "
        read name
        echo "Enter City: "
        read city
        echo "$roll | $name | $city" >>"$file"
        ;;
    6) exit ;;
    *) echo "Invalid choice" ;;
    esac
    echo "Press y to continue, press any other key to exit!"
    read i
    if [ "$i" != "y" ]; then
        exit
    fi
done
