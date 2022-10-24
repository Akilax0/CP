visited = set() # Set to keep track of visited nodes of graph.

def dfs(visited, graph, node):  #function for dfs 
    if node not in visited:
        print (node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)


x = list(input().split())
n = int(x[0])
m = int(x[1])

letters = {}
langs = {}

root = set()

for i in range(1,n+1):
    x = list(input().split())
    if(len(x)==5):
        letters[int(x[1])] = [x[2],int(x[3]),int(x[4])]
        root.add(int(x[3]))
        root.add(int(x[4]))
    else:
        langs[int(x[1])] = x[2]
#print(letters)
#print(langs)
r = 1
for i in letters:
   
    if i not in root:
        r = i

        
for j in range(m):
    s = input()
    
    
    ans = []
    curr = r
    
    q = []
    q.append(curr)
    
    while(len(q)!=0):
        
        curr = q.pop(0)
      

        if curr in letters:
            # print(letters[curr][0])
            if letters[curr][0] in s:
                q.append(letters[curr][1])
             
            else:
                q.append(letters[curr][2])
                q.append(letters[curr][1])
               
        else:
            ans.append(langs[curr])
            

    ans.sort()
    for k in ans:
        print(k,end=" ")
    print("")
        
    
        