f1 = open("c1.txt", "r")

f2 = open("c2.txt", "r")

data1=str(f1.read())
data2=str(f2.read())

if (data1==data2):
    print("data1==data2")
elif (data1<data2):
    print("data1<data2")
else:
     print("data1>data2")
    
