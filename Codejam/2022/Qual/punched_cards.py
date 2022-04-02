n  = int(input())

for i in range(1,n+1):
    r,c = [int(x) for x in input().split()]
    
    print("Case #{}:".format(i))
    print('.',end="")
    print('.+',end="")
    for j in range(c-1):
        print('-+',end="")
    print("")
    print('.',end="")
    for j in range(c):
        print('.|',end="")
    print("")

    print('+',end="")
    for j in range(c):
        print('-+',end="")
    print("")
    for k in range(r-1):

        print('|',end="")
        for j in range(c):
            print('.|',end="")
        print("")
        print('+',end="")
        for j in range(c):
            print('-+',end="")
        print("")

    # print(r,c)
