def simple_interest(p,t,r): 
    
    si = (p * t * r)/100
      
    print('The Simple Interest is', si) 
    return si

a=int(input("Are you a senior citizen?(Yes=1/No=0)"))

if a==1:
    t=int(input("Enter year duration"))
    p=int(input("Enter amount"))
    simple_interest(p,t,0.12)
elif a==0:
    t=int(input("Enter year duration"))
    p=int(input("Enter amount"))
    simple_interest(p,t,0.1)

else:
    print("Invalid Input")
