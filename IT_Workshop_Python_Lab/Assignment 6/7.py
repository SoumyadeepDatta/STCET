meter={1:1.2,2:4,3:2.1,4:5,5:4.5}
print(meter)
m_to_cm={}
for key,value in meter.items():
    m_to_cm[key]=value*100

print(m_to_cm)

cm_to_m={}

for key,value in m_to_cm.items():
    cm_to_m[key]=value/100

print(cm_to_m)
