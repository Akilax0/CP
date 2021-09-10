
#include<bits/stdc++.h>
using namespace std;

// Easy

// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> ans(n+1);
        
        if(n==1)
            return 0;
        else if(n==2)
            return min(cost[0],cost[1]);
        else{
            
            ans[0] = cost[0];
            ans[1] = cost[1];
            
            for(int i=2;i<n;i++){
                ans[i] = cost[i] + min(ans[i-1],ans[i-2]);
            }
            
            return min(ans[n-1],ans[n-2]);
        }
    }
};