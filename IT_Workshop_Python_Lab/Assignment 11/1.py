def recur_fibo(n):  
   if n <= 1:  
       return n  
   else:  
       return(recur_fibo(n-1) + recur_fibo(n-2))  
  
nterms = int(input("Enter no. of terms"))  
 
if nterms <= 0:  
   print("Enter a positive integer")  
else:  
   print("Fibonacci sequence:")  
   for i in range(nterms):  
       print(recur_fibo(i))

def fibo(n):  
    a = 0
    b = 1
    if n <= 1:  
       return n
    else:
        for i in range(1,n):
            c = a + b
            a = b
            b = c
            
        return b

nterms = int(input("Enter no of terms"))  
 
if nterms <= 0:  
   print("Enter a positive integer")  
else:  
   print("Fibonacci sequence:")  
   for i in range(nterms):  
       print(fibo(i))
