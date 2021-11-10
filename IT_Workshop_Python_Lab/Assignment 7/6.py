l1=[]
l2=[]
n = int(input("Enter number of elements : "))
print("For list 1:")
for i in range(0, n): 
    ele = int(input()) 
    l1.append(ele)

print("For list 2:")
for i in range(0, n): 
    ele = int(input()) 
    l2.append(ele)

l1.sort()
l2.sort()
    
if l1 == l2: 
    print ("The lists l1 and l3 are the same") 
else: 
    print ("The lists l1 and l3 are not the same") 
