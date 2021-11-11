import random

mylist = [1,2,3,4,5,6]
mydict = {1:0,2:0,3:0,4:0,5:0,6:0,}
#print(random.choice(mylist))

for i in range (6000):
    face=int(random.choice(mylist))
    mydict[face]+=1

print(mydict)
