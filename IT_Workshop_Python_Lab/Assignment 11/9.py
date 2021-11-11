def factorial(x):
    fact = 1
    for i in range(1,x+1):
        fact = fact * i
    return fact
n = int(input("Enter n value: "))

r = int(input("ENter r value: "))


MA1 = factorial(n)/(factorial(r)*factorial(n-r))


print("Answer for ncr is: ",MA1)
