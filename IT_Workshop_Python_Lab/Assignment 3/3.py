def name(s):

    l = s.split()
    new = ""


    for i in range(len(l) ):
        s = l[i]


        new += (s[0].upper() + '.')

    new=new[:-1]


    return new



s = "Soumyadeep Datta"
print(name(s))
