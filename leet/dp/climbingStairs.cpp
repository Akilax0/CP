#include<bits/stdc++.h>
using namespace std;

/*
Clasic dp question can be solved with fibannocci

*/
class Solution {
public:
    int climbStairs(int n) {
        int arr[46];
        arr[1]=1;
        arr[2]=2;
        
        for(int i=3;i<=45;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        
        return arr[n];
    }
};