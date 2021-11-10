d1 = {1: "Sun", 2 : "Mon"} 
  

print("initial dictionary : ", str(d1)) 
  

d2 = {v: k for k, v in d1.items()} 
  

print("inverse mapped dictionary : ", str(d2))
