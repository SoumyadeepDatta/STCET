def pypart(n):     
    # outer loop to handle number of rows 
    # n in this case 
    for i in range(0, n): 
        # inner loop to handle number of columns 
        # values changing acc. to outer loop 
        for j in range(0, i+1):           
            # printing stars 
            print("* ",end="")
        # ending line after each row 
        print("\r") 

def pypart2(n): 
      
    # number of spaces 
    k = 2*n - 2
  
    # outer loop to handle number of rows 
    for i in range(0, n): 
         # inner loop to handle number spaces 
        # values changing acc. to requirement 
        for j in range(0, k): 
            print(end=" ")     
        # decrementing k after each loop 
        k = k - 2      
        # inner loop to handle number of columns 
        # values changing acc. to outer loop 
        for j in range(0, i+1):           
            # printing stars 
            print("* ", end="")       
        # ending line after each row 
        print("\r") 

def triangle(n):     
    # number of spaces 
    k = 2*n - 2  
    # outer loop to handle number of rows 
    for i in range(0, n): 
        # inner loop to handle number spaces 
        # values changing acc. to requirement 
        for j in range(0, k): 
            print(end=" ")      
        # decrementing k after each loop 
        k = k - 1    
        # inner loop to handle number of columns 
        # values changing acc. to outer loop 
        for j in range(0, i+1):           
            # printing stars 
            print("* ", end="")    
        # ending line after each row 
        print("\r") 

def numpat(n):       
    # initialising starting number  
    num = 1 
    # outer loop to handle number of rows 
    for i in range(0, n):       
        # re assigning num 
        num = 1      
        # inner loop to handle number of columns 
            # values changing acc. to outer loop 
        for j in range(0, i+1):         
                # printing number 
            print(num, end=" ")         
            # incrementing number at each column 
            num = num + 1
             # ending line after each row 
        print("\r") 

def contnum(n):      
    # initializing starting number  
    num = 1  
    # outer loop to handle number of rows 
    for i in range(0, n):       
        # not re assigning num 
        # num = 1       
        # inner loop to handle number of columns 
        # values changing acc. to outer loop 
        for j in range(0, i+1):           
            # printing number 
            print(num, end=" ")           
            # incrementing number at each column 
            num = num + 1      
        # ending line after each row 
        print("\r")
