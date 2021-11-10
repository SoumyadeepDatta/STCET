try:
    lines = ''
    with open('demofile.txt') as f:
        lines=f.read()[::-1]
    with open('demofile.txt','w') as f:
        f.write(lines)
        

except:
    print('Error')
