T = int(input())
for t in range(T):
    P,D = map(float,input().split())

    for i in range(5):
        newP= (0.4*P)/(0.4*P + 0.6*(1-P))
        if newP<D:
            print(i+1)
            break
        else:
            P=newP
    else:
        print("NOT SUITABLE")
