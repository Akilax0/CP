# Divide and Conquer

Breaking problems into non overlapping same type of subproblems

## LinearSearch(A, low, high , key)

	if high < low:
		return NOT_FOUND
	if A[low] ==key:
		return low
	return LinearSearch(A,low+1,high,key)


Rscurrence defining worst-case time:

T(n) = T(n-1) +c
T(0) = c

theta(n)

## BinarySearch(A,low,high,key)

### Recursive 
	if high < low:
		return -1
	mid = [low + (high-low)/2]
	if key == A[mid]:
		return mid
	else if key < A[mid]:
		return BinarySearch(A,low,mid-1,key)
	else:
		return BinarySearch(A,mid+1,high,key)


Recurrence defining worst-case time:

T(n) = T(n/2) + c
T(0) = c

theta(logn)

### Iterative 

	while low < high:
		mid = [low+(high-low)/2]
		if key = A[mid]
			return mid
		else if key < A[mid]:
			high = mid - 1
		else: 
			low = mid + 1

	return low - 1




## MultPoly(A,B,n) - naive

	product = Array[2n-1]
	for i from 0 to 2n-2:
		product[i]=0
	for i from 0 to n-1:
		for j from 0 to n-1:
			product[i+j] = product[i+j] + A[i]*B[j]

	return product

runtime O(n^2)

## Mult2(A,B,n,a1,b1) -  naive divde and conquer
	R = array[0...2n-1]
	if n=1:
		R[0] = A[al] * B[bl] ; return R

	R[0...n-2] = Mult2(A,B,n/2,al,bl)
	R[n...2n-2] = Mult2(A,B,n/2,al+n/2,bl+n/2)

	D0E1 = Mult2(A,B,n/2,al,bl+n/2)
	D1E0 = Mult2(A,B,n/2,al+n/2,bl)

	R[n/2..........n+n/2] += D1E0 + D0E1

	return R


runtime theta(n^2)






