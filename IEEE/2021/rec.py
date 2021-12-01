ans =0

def rec(k,i,d):
    
    if(k==0):
        return 1

    if(i >= len(d)):
        return 0 

    for j in range(d[i][0]+1):
        if(j * d[i][1] <= k):
            return rec(k-(j*d[i][1]),i+1,d) + rec(k,i+1,d)


n,k = map(int,input().split())
d = {}

for i in range(n):
    a,b = map(int,input().split())

    d[i] = [a,b]

ret = rec(k,0,d)
print(ret)


