import re

n = int(input())
t = int(input())
dim = input().split(',')

r = int(dim[0])
c = int(dim[1])


C = input()
C = C[0]



words = []
for _ in range(n):
    p = input()
    words.append(p)

letters = []
for _ in range(t):
    text = input()

    #clean = re.compile('<.*?>')
    text = re.sub('<.*?>', '',text)

    text = text.replace(' ','_')
    # print(text)
    letters.extend([c for c in text])


grid = {}
for i in range(r):
   
    for j in range(c):
        if letters[i*c+j] not in grid:
            grid[letters[i*c+j]] = []

        grid[letters[i*c+j]].append([i,j])


if(C=='S'):
    for word in words:
        f = True
        ans = ""
        
        for l in word:
            if l not in grid:
                print("0")
                f= False
                break
            ans = ans + str(grid[l][0][0]+1)
            ans = ans + ","
            ans = ans + str(grid[l][0][1]+1)
            ans = ans + ","

        if f==True:
            print(ans[:-1])
else:
    for word in words:
        f = True
        ans = ""
        for l in word:
            if l not in grid:
                print("0")
                f = False
                break
            ans = ans + str(grid[l][-1][0]+1)
            ans = ans + ","
            ans = ans + str(grid[l][-1][1]+1)
            ans = ans + ","
        if f==True:
            print(ans[:-1])