def maximum(a, b, c):
    if (a >= b) and (a >= c):
        largest = a

    elif (b >= a) and (b >= c):
        largest = b
    else:
        largest = c

    return largest


def minimum(a, b, c):
    if (a <= b) and (a <= c):
        smallest = a

    elif (b <= a) and (b <= c):
        smallest = b
    else:
        smallest = c

    return smallest



a,b,c=input("Enter 3 no.s:").split()

a=int(a)
b=int(b)
c=int(c)

print("\nMax: ",maximum(a,b,c))
print("\nMin: ",minimum(a,b,c))
