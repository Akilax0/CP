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




