#include<bits/stdc++.h>
using namespace std;

/**
 *Arriving at a solution using kadanes algorithm
 	Here, the logic is to calculate the difference (maxCur += prices[i] - prices[i-1]) of 
	the original array, and find a contiguous subarray giving maximum profit. 
	If the difference falls below 0, reset it to zero.

	max sub array
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur =0 , maxSoFar=0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            maxCur = max(0,maxCur+=prices[i]-prices[i-1]);
            maxSoFar = max(maxSoFar,maxCur);
        }
        
        return maxSoFar;
    }
};
