def prime(num):
    if num > 1:

        for i in range(2, num):
            if (num % i) == 0:
                # print(num, "is not a prime number")

                break
        else:
            print(num)

for i in range (1001):
    prime(i)
