import calendar

#print(calendar.weekday(2016, 5, 15)) 
  
y=int(input("Enter the year: "))
 
for m in range(1,13):
     #print(m, ":", calendar.month_abbr[m], "First monday is :",calendar.weekday(y, 5, 15) )
     for d in range (1,8):
         if(int(calendar.weekday(y, m, d))==0):
             print("First monday of ", calendar.month_abbr[m], " is :",d,"th day of",calendar.month_abbr[m] )
