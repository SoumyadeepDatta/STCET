def maximum(a, b, c): 
  
    if (a >= b) and (a >= c): 
        largest = a 
  
    elif (b >= a) and (b >= c): 
        largest = b 
    else: 
        largest = c 
          
    return largest 
  

def minimum(a, b, c): 
  
    if (a <= b) and (a <= c): 
        smallest = a 
  
    elif (b <= a) and (b <= c): 
        smallest = b 
    else: 
        smallest = c 
          
    return smallest 
  
  

a = 10
b = 14
c = 12
print(maximum(a, b, c))
print(minimum(a, b, c))
