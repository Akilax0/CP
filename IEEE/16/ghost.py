import sys
sys.setrecursionlimit(10000000)
inf = 1111111
arr = [[''  for _ in range(505)] for __ in range(505)]
grid = [ [inf for _ in range(505)] for __ in range(505)]
vis = [ [False for _ in range(505)] for __ in range(505)]
parent = {}

# D, L, R, U
nei = [(1, 0), (0, -1), (0, 1), (-1, 0)]

def is_safe(i, j, n, m):
    if (not vis[i][j] and i < n and i >= 0 and j < m and j >= 0 and (arr[i][j] == '.' or arr[i][j] == 'G' or arr[i][j] == 'P')):
        return True
    return False

def dfs(i, j, n, m):
    vis[i][j] = True
    for k in nei:
        if (is_safe(i + k[0], j + k[1], n, m)):
            dfs(i + k[0], j + k[1], n, m)
        
def dfs2(i, j, n, m, mx_id):
    vis[i][j] = True
    if not (grid[i][j] == inf):
        if (grid[mx_id[0]][mx_id[1]] < grid[i][j]):
            mx_id = (i, j)

    for k in nei:
        if (is_safe(i + k[0], j + k[1], n, m)):
            mx_id = dfs2(i + k[0], j + k[1], n, m, mx_id)
    return mx_id

def dfs3(i, j, n, m, lex_id):
    vis[i][j] = True
    if ((i,j)<lex_id):
        lex_id = (i, j)
    
    for k in nei:
        if (is_safe(i + k[0], j + k[1], n, m)):
            lex_id = dfs3(i + k[0], j + k[1], n, m, lex_id)
    return lex_id


def bfs(start, n, m):
    q = []
    q.append(start)
    grid[start[0]][start[1]] = 0
    vis[start[0]][start[1]] = True
    parent[(start[0], start[1])] = (-1, -1)
    while (len(q) > 0):
        u = q.pop(0)
        for k in nei:
            if (is_safe(u[0] + k[0], u[1] + k[1], n, m)):
                vis[u[0] + k[0]][u[1] + k[1]] = True
                parent[(u[0] + k[0], u[1] + k[1])] = u
                grid[u[0] + k[0]][u[1] + k[1]] = min(grid[u[0] + k[0]][u[1] + k[1]], grid[u[0]][u[1]] + 1)
                q.append((u[0] + k[0], u[1] + k[1]))


def direction(start, end):
    if (start[0] < end[0]):
        return 'D'
    if (start[0] > end[0]):
        return 'U'
    if (start[1] > end[1]):
        return 'L'
    if (start[1] < end[1]):
        return 'R'

def show(arr, n, m):
    for i in range(n):
        print(arr[i][:m])


t = int(input())
T = t
while (t>0):
    t=t-1
    print(f"Case #{T - t}: ", end='')
    n, m = list(map(int, input().split()))
    P = (-1,-1)
    G = []
    for i in range(n):
        s = input()
        for j in range(m):
            arr[i][j] = s[j]
            if (arr[i][j] == 'P'):
                P = (i, j)
            elif (arr[i][j] == 'G'):
                G.append((i, j))

    # show(arr, n, m)

    vis = [ [False for _ in range(505)] for __ in range(505)]
    for x in G:
        dfs(x[0], x[1], n, m)


    if not vis[P[0]][P[1]]:
        print("INFINITE ", end='')

        vis = [ [False for _ in range(505)] for __ in range(505)]
        dest = dfs3(P[0], P[1], n, m, P)

        vis = [ [False for _ in range(505)] for __ in range(505)]
        bfs(P, n, m)

        ans_str = ""
        while (not(parent[dest][0] == -1 and parent[dest][1] == -1)):
            ans_str += direction(parent[dest], dest)
            dest = parent[dest]
        if(len(ans_str)==0): 
            print('STAY')
        else: print(ans_str[::-1])

    else:
        grid = [ [inf for _ in range(505)] for __ in range(505)]

        # print(G)
        for g in G:
            vis = [ [False for _ in range(505)] for __ in range(505)]
            bfs(g, n, m)

        # show(grid, n, m)

        vis = [ [False for _ in range(505)] for __ in range(505)]
        dest = dfs2(P[0], P[1], n, m, P)
        value = grid[dest[0]][dest[1]]
        for i in range(n):
            for j in range(m):
                grid[i][j] = inf
                vis[i][j] = False

        bfs(P, n, m)
        ans_str = ""
        while (not(parent[dest][0] == -1 and parent[dest][1] == -1)):
            ans_str += direction(parent[dest], dest)
            dest = parent[dest]
        print(value-1, ans_str[::-1])

