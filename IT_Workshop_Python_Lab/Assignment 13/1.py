import datetime

#x = datetime.datetime(2016,12,31)

#print(x)
#print(x.strftime("%j"))

#print("Enter starting year & ending year")


a=int(input("Enter starting year"))
b=int(input("Enter ending year"))

count=0


for i in range (a,b+1):
    x = datetime.datetime(i,12,31)
    if (int(x.strftime("%j"))==366):
        print(i,"is leap year")
        count+=1
    else:
        print(i,"is not leap year")


print("Total no. of leap year :",count)
