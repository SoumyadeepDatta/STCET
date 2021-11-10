with open ("new.txt","r") as f:
    data=f.read()

with open ("case_change.txt","w") as f2:
    f2.write(data.swapcase())
    
