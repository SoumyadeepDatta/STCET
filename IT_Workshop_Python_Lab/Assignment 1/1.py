#a)
myname='Soumyadeep'
print(myname)
#b)
your_name='John'

print('Hello ! ' + your_name )
#c)
a,b=input().split()
a=int(a)
b=int(b)
print(a+b)
#d)
a,b=input().split()
a=int(a)
b=int(b)
print(a-b)
#e)
a,b=input().split()
a=int(a)
b=int(b)
print(a*b)
#f)
a,b=input().split()
a=int(a)
b=int(b)
print('Div=',a/b,'Rem=',a%b)
#g)
a,b=input().split()
a=int(a)
b=int(b)
print('Div=',int(a/b),'Rem=',a%b)
#h)
a,b=input().split()
a=int(a)
b=int(b)
res=int(1)
for i in range (1,b+1):
    res=res*a;
print(res)
#i
s1='Soumyadeep'
print(s1)
#j
print(s1[0])
print(s1[5])
#k
print('new line\ntab space\tword')
#l
print(r'new line\ntab space\tword')
#m
num='4'
num=int(num)
print(num+1)
#n
st=str(num)
print(st)
#o
str1='Hello'
str2='World'
res='{}{}'.format(str1,str2)# concatenate without using +
print(res)
#p
str1='Hello'
str2='World'
res1=str1+str2
print(res1)
#q
a=int(input('int='))
b=float(input('float='))
print(a*b+3)
print(round(a*b+3,2))
