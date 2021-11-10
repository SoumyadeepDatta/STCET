a=[]
while 1:
    n=input("No.s:")
    if n== 'done' :
        break
    try :
        n=float(n)
    except:
        print('Invalid Input')
        continue
    a.append(n)

print('Avg :',round(sum(a)/len(a),2))

print('Max :',max(a))
print('Min :',min(a))
