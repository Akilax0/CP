# Greedy Algorithms in General

## Key Features

### Reduction to Subproblem

- Make a first move
- Solve a problem of the same kind
- Smaller: fewer digits, fewer fuel stations

### Safe move

- Optimal solution consistent with the first move.
- Not all first moves safe.
- Often greedy solution isnt the best

## General Strategy

Problem ------------------->  Safe Move
   |       greedy choice         |
   |				 |
   |-----------------------------|

- Make a greedy choics
- Prove it is a safe move
- Reduction to subproblem
- solve the subproblem



## Example Algorithms

### MinRefills(x,n,L) 

Find minimum number of refills

- x = fuel station array
- n = number od stations
- L = Maximum distance on a full fuel tank


	numRefills =0, currentRefill =0
	while currentRefill <= n:
		lastRefill = currentRefill
		while (currentRefill <= n && x[currentRefill+1] - x[lastRefill] <= L):
			currentRefill ++;
		if currentRefill == lastRefill:
			return "IMPOSSIBLE"
		if currentRefill <= n:
			numRefills = numRefills + 1
	return numRefills

O (n)

### MinGroups(C)

Find minimum number of groups such that at most age difference between any two children in a group be an year.

- C = children array


	m = len(C)
	for each partiton into groups
	C = G1 U G2 U ..... Gk

		good = true
		for i from 1 to k:
			if max(Gi) - min(Gi) > 1:
				good = false
		if good:
			m = min(m,k)
	return m

 lower bound = 2^n

### PointsCoverSorted(x1,....,xn)

	R = {}
	i = 1;

	while(i<=n):
		[l,r] = [xi,xi+1]
		R = R U {[l,r]}
		i = i + 1
		while(i<=n and xi<=r):
			i = i + 1
	return R

### Knapsack(W, w1,v1,.......,wn,vn)

	A = [0,0,....0]
	V = 0

	repeat n times:
		if W=0:
			return (V,A)
		select i with wi > 0 and max vi/wi
		a = min(wi,W)
		V = V + a(vi/wi)
		wi = wi - a
		A[i] = A[i] + a
		W = W - a
	return (V,A)



