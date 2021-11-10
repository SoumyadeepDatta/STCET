def binarySearch (arr, l, r, x): 
  

    if r >= l: 
  
        mid = l + (r - l) // 2
  

        if arr[mid] == x: 
            return mid 
          
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        else: 
            return binarySearch(arr, mid + 1, r, x) 
  
    else: 
        return -1
def search(arr, x): 
  
    for i in range(len(arr)): 
  
        if arr[i] == x: 
            return i 
  
    return -1
arr = [ 2, 3, 4, 10, 40 ]
print("Array is:")
print(arr)
x=int(input("Enter element"))
print("1.binary search\n2.linear search")
c=int(input())
if c==1:
    if binarySearch(arr,0,5,x)==-1:
        print("Item not found")
    else:
        print("Item found at position :",binarySearch(arr,0,5,x)+1)
elif c==2:
    if search(arr,x)==-1:
        print("Item not found")
    else:
        print("Item found at position :",search(arr,x)+1)
else:
    print("Invalid input")
