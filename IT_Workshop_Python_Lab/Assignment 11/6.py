def func (name, *fav):
    print("\n",name,"likes to read")
    for subject in fav:
        print(subject)

func("S1","Maths")

func("S1","Maths","Physics","DBMS")
