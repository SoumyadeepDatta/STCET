import sys
prog_name=sys.argv[0]
args=sys.argv[1:]
count=len(args)
print(prog_name)
print(count)
for i in args:
    print(args[i])
