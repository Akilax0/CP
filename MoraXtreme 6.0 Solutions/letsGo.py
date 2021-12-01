rows = int(input())
k = 0
if (2<=rows and 20>=rows):
    for i in range (rows-2, -1, -1):
        for j in range (k+2,0, -1):
            print(end=" ")

        for j in range(0, rows-1):
            print("*", end=" ")
        print("")

    for i in range(rows, -1, -1):
        for j in range(k, 0, -1):
            print(end=" ")
        k = k + 1
        for j in range(0, i + 1):
            print("*", end=" ")
        print("")
