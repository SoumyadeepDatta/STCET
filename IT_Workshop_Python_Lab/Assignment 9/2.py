list1=("Bread","Coffee","Sugar","Salt")
#print("Enter alphabet:")
x=str(input("Enter alphabet (Only Uppercase):"))

for item in list1:
    item=str(item)
    if (item[0]==x ):
        print(item)
