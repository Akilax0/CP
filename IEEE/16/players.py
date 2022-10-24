
from platform import platform




A = []

def rec(players,i, n, ans):
    #print(ans)

    if(i==len(players) and n>=0):
        for i in ans:
            print(i)
        #A.append(ans)
        #print(A)
        exit(0) 
    if(n<0):
        return 

    for j in players[i]:
        ans[i]=j[0]
        rec(players,i+1,n-j[1],ans)
        

    
        
    # return rec(players, i+1, n, ans) + rec()
    
n = int(input())
players = []
for k in range(5):
    c = int(input())
    
    t = []
    for i in range(c):
        s = input().split()
        s[1] = int(s[1])
        t.append(s)

    players.append(t)

ans = ["None" for i in range(5)]
rec(players,i,n,ans)
#for i in range(0,5):
 #   print(ans[i])
#print(A)
        
    
    
