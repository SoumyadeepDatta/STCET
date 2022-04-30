stack = []

def push(val):
    stack.append(val)

def pop():
    if len(stack) == 0:
        return ""
    return stack.pop()

def peek():
    if len(stack) == 0:
        return ""
    return stack[len(stack) - 1]

if __name__ == "__main__":
    while True:
        print("1. Push\n2. Pop\n3. Peek\n4. Exit")
        n = int(input())
        if n == 1:
            push(input("Item : "))
        elif n == 2:
            print("Poped : " + pop())
        elif n == 3:
            print(peek())
        elif n == 4:
            exit()
        else:
            print("Invalid Input !!!")