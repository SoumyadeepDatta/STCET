with open('wordlen.txt','r') as f:
    for line in f:
        w=line.split()
        #words+=len(words)
    max_len=len(max(w,key=len))

print(max_len)
