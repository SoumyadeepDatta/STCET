import  math

a,b,c=input("Enter coeff of x2 , x1 and x0 :").split()
a=float(a)
b=float(b)
c=float(c)
d=float(b*b - 4*a*c)
if d < 0 :
    print("\nRoot is imaginary")

else :
    r1=float((-b+math.sqrt(d))/(2*a))
    r2 = float((-b - math.sqrt(d)) / (2 * a))
    print("\nRoots are :",r1," and ",r2)
