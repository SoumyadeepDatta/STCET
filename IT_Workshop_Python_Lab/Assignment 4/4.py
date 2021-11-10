'''
In python Switch-case can be implemented by using a
if-elif-else ladder inside a while or do-while loop
'''
while(1):
    z=int(input("No (0 to exit):"))
    if(z==1):
        print("\nSun")
    elif(z==2):
        print("\nMon")
    elif (z == 3):
        print("\nTue")
    elif (z == 4):
        print("\nWed")
    elif (z == 5):
        print("\nThu")
    elif (z == 6):
        print("\nFri")
    elif (z == 7):
        print("\nSat")
    elif (z==0):
        break
    else:
        print("\nInvalid input")
