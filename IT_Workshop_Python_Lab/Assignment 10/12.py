with open ("file1.txt","r") as f1:
    data1=f1.read()

with open ("file2.txt","r") as f2:
    data2=f2.read()
    

with open ("merged.txt","a") as f3:
    f3.write(data1)
    f3.write(data2)



    
