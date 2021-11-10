d1 = {'Name': 's', 'class': 2, 'name': 'f', 'subject': 'maths', 'class': 5, 'name': 'f'}
d2 = {}
 
for key,value in d1.items():
  if value not in d2.values():
    d2[key] = value
 

print(d2)
