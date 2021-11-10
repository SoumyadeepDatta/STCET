with open("demo.txt") as f:
    with open("out.txt", "w") as f1:
        for x in f:
            f1.write(x)
