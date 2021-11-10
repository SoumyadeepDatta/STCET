tup0=(1,2,3)
print(tup0)    #prints the tuple
del(tup0)      #deletes the tuple
#print(tup0)    #deleted tuple cannot be printed


tup1=(1,2,3)
tup2=(10,20,30)
new=tup1+tup2    #concatenates two tuples
print(new)


tup3=(5,)
tup3=tup3*5   #stores same item several times
print(tup3)

tup4=(1,2,3,10,20,30) 
print(tup4[2:4])      #prints tuple element without using loops


tup=(1,2,3)
new=list(tup)   #converts tuple into list
print(new)


tup=(1,2,3,10,20,30)
print(max(tup))   #prints max element in tuple
print(min(tup))   #prints max element in tuple
print(len(tup))   ##prints length of tuple


x = (5, 10, 15, 20)
y = reversed(x)  # Reversed the tuple
print(tuple(y))


num = [10,20,30,(10,20),40]
ctr = 0
for n in num:
    if isinstance(n, tuple):   #count the elements in a list until an element is a tuple
        break
    ctr += 1
print(ctr)


#create a tuple
tuplex = tuple("index tuple")
print(tuplex)
#get index of the first item whose value is passed as parameter
index = tuplex.index("p")
print(index)
#define the index from which you want to search
index = tuplex.index("p", 5)
print(index)
#define the segment of the tuple to be searched
index = tuplex.index("e", 3, 6)
print(index)
#if item not exists in the tuple return ValueError Exception
#index = tuplex.index("y")



#create a tuple
tuplex = (2, 4, 3, 5, 4, 6, 7, 8, 6, 1)
#used tuple[start:stop] the start index is inclusive and the stop index
slice = tuplex[3:5]
#is exclusive
print(slice)
#if the start index isn't defined, is taken from the beg inning of the tuple
slice = tuplex[:6]
print(slice)
#if the end index isn't defined, is taken until the end of the tuple
slice = tuplex[5:]
print(slice)
#if neither is defined, returns the full tuple
slice = tuplex[:]
print(slice)
#The indexes can be defined with negative values
slice = tuplex[-8:-4]
print(slice)
#create another tuple
tuplex = tuple("HELLO WORLD")
print(tuplex)
#step specify an increment between the elements to cut of the tuple
#tuple[start:stop:step]
slice = tuplex[2:9:2]
print(slice)
#returns a tuple with a jump every 3 items
slice = tuplex[::4]
print(slice)
#when step is negative the jump is made back
slice = tuplex[9:2:-4]
print(slice)
