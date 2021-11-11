def add(num1, num2): 
    return num1 + num2 
  
# Function to subtract two numbers  
def subtract(num1, num2): 
    return num1 - num2 
  
# Function to multiply two numbers 
def multiply(num1, num2): 
    return num1 * num2 
  
# Function to divide two numbers 
def divide(num1, num2): 
    return num1 / num2

def exp(exponent,number):
    power = 1

    for i in range(1, exponent + 1):
        power = power * number
        

    return power    
  
print("Please select operation -\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exponent\n") 
  
  
# Take input from the user  
select = int(input("Select operations form 1, 2, 3, 4, 5 :")) 
  
number_1 = int(input("Enter first number: ")) 
number_2 = int(input("Enter second number: ")) 
  
if select == 1: 
    print(number_1, "+", number_2, "=", 
                    add(number_1, number_2)) 
  
elif select == 2: 
    print(number_1, "-", number_2, "=", 
                    subtract(number_1, number_2)) 
  
elif select == 3: 
    print(number_1, "*", number_2, "=", 
                    multiply(number_1, number_2)) 
  
elif select == 4: 
    print(number_1, "/", number_2, "=", 
                    divide(number_1, number_2)) 
elif select == 5:
    print(number_1, "^", number_2, "=", 
                    exp(number_2, number_1)) 

else: 
    print("Invalid input")
