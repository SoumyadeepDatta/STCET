def prime(num):
    if num > 1:

        for i in range(2, num):
            if (num % i) == 0:
                print(num, "is not a prime number")

                break
        else:
            print(num, "is a prime number")


    else:
        print(num, "is not a prime number")

prime(16)
prime(17)
prime(11)
prime(9)
