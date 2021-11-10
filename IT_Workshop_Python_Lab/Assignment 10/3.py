import os
if os.path.exists("check.txt"):
    os.remove("check.txt")
else:
    print("The file does not exist")
