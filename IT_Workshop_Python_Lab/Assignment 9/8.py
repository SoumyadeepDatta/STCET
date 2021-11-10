bdays={"Anirban":"2.12.2001","Rohit":"5.10.2000","Arpan":"7.7.1999"}
print(bdays)


flag=0
key1=str(input("Enter key to find"))


if key1 in bdays.keys():
  print ("Already present")
else:
  print ("Absent")
  flag=1

if (flag==1):
  x=str(input("Enter value for "+ key1))
  bdays[key1]=x

print(bdays)

#bdays=sorted(bdays)

for key in sorted(bdays):
  print(key,bdays[key],end=' ')
