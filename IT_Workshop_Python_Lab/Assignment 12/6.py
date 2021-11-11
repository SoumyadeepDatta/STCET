import functions as f

while 1:
    print("Enter the function number (eg:-1 for function 1)\nPress 6 to exit")
    c = int(input())
    if c == 1:
        print("Enter x and y:")
        x, y = input().split()
        x = int(x)
        y = int(y)
        print("Result=", f.f1(x, y))
    elif c == 2:
        print("Enter n and r:")
        n, r = input().split()
        n = int(n)
        r = int(r)
        print("Result=", f.f2(n, r))
    elif c == 3:
        n = int(input("Enter n:"))
        print("Result=", f.f3(n))
    elif c == 4:
        print("Enter m and n")
        m, n = input().split()
        m = int(m)
        n = int(n)
        print("Result=", f.f4(m, n))
    elif c == 5:
        print("Enter m and x")
        m, x = input().split()
        m = int(m)
        x = int(n)
        print("Result=", f.f5(m, x))
    elif c == 6:
        print("Thanks")
        break
    else:
        print("Wrong input")
