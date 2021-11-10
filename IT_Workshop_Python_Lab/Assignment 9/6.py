employe = {1: {'name': 'Mike', 'age': '25', 'sex': 'Male'},
          2: {'name': 'Ross', 'age': '27', 'sex': 'Male'}}


for e_id, e_info in employe.items():
    print("\nPerson ID:", e_id)
    
    for key in e_info:
        print(key + ':', e_info[key])
