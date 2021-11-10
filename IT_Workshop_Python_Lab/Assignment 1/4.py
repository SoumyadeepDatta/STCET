p,r,t=input("Enter principle amount, interest rate and years:").split()
p=float(p)
r=float(r)
t=int(t)

print("\nTotal: ",round(p*r*t/100,2))
