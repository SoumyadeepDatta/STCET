def returnPrice(customer): 
      
    c=0
    sum = 0
    for i in customer: 
        sum = sum + customer[i] 
        c=c+1  
    print(c,"items")
    return sum
  

customer = {'Rice':200, 'Vegetables':91, 'Fruits':72, 'Soap':50} 
print("MRP Rs:", returnPrice(customer))
