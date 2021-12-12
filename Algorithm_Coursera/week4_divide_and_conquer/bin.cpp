#include<bits/stdc++.h>
using namespace std;


int A[209152];


BinSearch(int low,int high, int key){
	
	
	if(high < low)
		return -1

	mid = [low + (high-low)/2]
	if(key == A[mid])
		return mid
	else if(key < A[mid])
		return BinarySearch(low,mid-1,key)
	else
		return BinarySearch(mid+1,high,key)
}

int main(){
	int low 



	return 0;
}
