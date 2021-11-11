def fngcd(a,b): 
    if(b==0): 
        return a 
    else: 
        return fngcd(b,a%b)



l=[]

n=int(input("Enter range"))
for k in range (n):
    x=int(input("Enter no."))
    l.append(x)


num1 = l[0] 
num2 = l[1] 
gcd = fngcd(num1, num2) 
  
for i in range(2, len(l)): 
    gcd = fngcd(gcd, l[i]) 
      
print("GCD is:")
print(gcd)
