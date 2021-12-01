import time
x_axis = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
y_axis = ['26', '25', '24', '23', '22', '21', '20', '19', '18', '17', '16', '15', '14', '13', '12', '11', '10', '9', '8', '7', '6', '5', '4', '3', '2', '1']
def get_childs(cell,n):#[x,y]
    sx = x_axis.index(cell[0])
    sy = y_axis.index(cell[1:])
    cell = [sx,sy]
    moves = [[-2,1],[-2,-1],[-1,2],[-1,-2],[1,2],[1,-2],[2,1],[2,-1]]
    arr = []
    for i in moves:
        c = [cell[0]+i[0],cell[1]+i[1]]
        if (c[0]>=0 and c[0]<n and c[1]>=0 and c[1]<n):
            arr.append(x_axis[c[0]]+y_axis[c[1]])
    return arr
    
def knightDistance (x, y):#knight distance is taken O(1) time using a pattern
    x, y = abs(x), abs(y)
    if (x<y): x, y = y, x

    if (x>2*y):
        n7, n8, n10 = 0,  (x + 2*y)//4,  (x - 2*y + 1)//4
    else:
        n7, n8, n10 = (2*y - x)//3, (2*x - y)//3,  0
    x -= 2*n8 + n7 + 2*n10
    y -= n8 + 2*n7 - n10

    if (x, y)==(1, 0): 
        if (n8>0): 
            x, y = 3, 1; n8-=1;
    if (x, y)==(2, 2):
        if (n8>0):
            x, y = 3, 1; n8-=1; n7+=1
    arr = [[0, 3, 2], [2, None, 2], [4]]
    return n7 + n8 + n10 + arr [y][x-y]
def h(start,goal,n):
    global x_axis,y_axis
    x_axis = x_axis[:n]
    y_axis = y_axis[-n:]
    sx = x_axis.index(start[0])
    sy = y_axis.index(start[1:])
    gx = x_axis.index(goal[0])
    gy = y_axis.index(goal[1:])
    move_count = 0
    if start==goal :
        return move_count
    if (((sx<=1 or sx>=n-1) and (sy<=1 or sy>=n-1)) or ((gx<=1 or gx>=n-1) and (gy<=1 or gy>=n-1))) and (abs(gx-sx)==1 and abs(gy-sy)==1):
        return 4 #exceptional case
    else:
        return knightDistance(gx-sx,gy-sy)
class DP: #dynamic programming approach
    def __init__(self,distance,startnode=''):
        self.distance = distance
        self.startnode = startnode
        self.N = len(distance)
        self.finished_state = (1<<self.N)-1
        self.minTourCost = 100000 #~infinite
        self.tour = []
        self.ransolver = False
        
    def get_tour(self):
        if not self.ransolver:
            self.solve()
        return self.tour
    def get_tour_cost(self):
        if not self.ranSolver:
            solve()
        
        return self.minTourCost
    def solve(self):
        state = 1 << self.startnode
        self.memo = {}
        self.prev = {}
        self.minTourCost = self.tsp(self.startnode, state)

        index = self.startnode
        while (True):
          self.tour.append(index)
          try:  
            nextIndex = self.prev[(index,state)]
            nextState = state | (1 << nextIndex)
            state = nextState
            index = nextIndex
          except:
            break
          
        
        self.ranSolver = True
    def tsp(self,i, state):

        # Done this tour. Return cost of going back to start node.
        if (state == self.finished_state): return 0

        # Return cached answer if already computed.
        try:
            return self.memo[(i,state)]
        
        except:
            minCost = 10000
            index = -1
            for next in range(self.N):

              # Skip if the next node has already been visited.
              if ((state & (1 << next)) != 0): continue

              nextState = state | (1 << next)
              newCost = self.distance[i][next] + self.tsp(next, nextState)
              if (newCost < minCost):
                minCost = newCost
                index = next
            self.prev[(i,state)] = index
            self.memo[(i,state)] = minCost
            return minCost
            
def find_path(knight,pawns,n):
    global x_axis,y_axis
    x_axis = x_axis[:n]
    y_axis = y_axis[-n:]
    open = []
    closed = []
    matrix = []
    pawns.insert(0,knight)
    N = len(pawns)
    if N==n*n: #full board case
        print(n,N-1,knight)
        print(' '.join(pawns[1:]))
        print('\n',N-1)
        return N-1
    for pawn in pawns:
        arr = []
        
        for i in pawns:
            arr.append(h(pawn,i,n))
        matrix.append(arr)    
    
    solver = DP(matrix,0)
    order = solver.get_tour()
    path = [pawns[i] for i in order]
    #print("Tour: " , path)
    cost = solver.get_tour_cost()
    print("Tour cost: " ,cost )
    return cost
    
if __name__ == '__main__':
    n,N,knight = input().split()
    pawns = input().split()
    find_path(knight,pawns,int(n))
    
    