import datetime
x = datetime.datetime.now()

print("Year : ",x.year)
#print(x.strftime("%A"))
print("Month : ",x.strftime("%m"))
print("Day : ",x.day)
print("Time : ",x.strftime("%X"))
print("Date & time : ",x)
