def get_gold(k):


    return k;
n,m = map(int,input().split())

gold = {}
dist = [0] * n
for i in range(n):
    dist[i] = [0]*n



for _ in range(n):
    k = int(input())
    gold[k] = get_gold(k)

for _ in range(m):
    x,y,d = map(int,input().split())

    dist[x].append(d)



print(n,m)
