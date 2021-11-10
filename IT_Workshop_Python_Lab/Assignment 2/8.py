try :
    h=int(input("Hours: "))
except:
    print("Enter numeric values")
    exit(-1)

try :
    r=float(input("Rate: "))
except:
    print("Enter numeric values")
    exit(-1)

print("Total :",round(r*h,2))
