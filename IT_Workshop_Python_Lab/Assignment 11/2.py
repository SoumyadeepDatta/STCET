def fact(n):
    if n<=1:
        return 1
    else:
        return n*fact(n-1)

rows = int(input("Enter the number of rows : "))

for i in range(0, rows):
    for j in range(1, rows-i):
        print("  ", end="")

    for k in range(0, i+1):
        ele = int(fact(i)/(fact(k)*fact(i-k)))
        print("  ", ele, end="")
    
    print()
