num = 0
tot = 0.0
while True:
    number = input("Enter a number")
    if number == 'done':
        break
    try :
        num1 = float(number)
    except:
        print('Invailed Input')
        continue
    num = num+1
    tot = tot + num1
print ('all done')
print ('Total =',tot,' Count =',num,' Avg =',float(tot/num))
