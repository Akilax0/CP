
#include<bits/stdc++.h>
using namespace std;

/**
 *	Kdanes algorithm for max subarray
 * */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCur = nums[0], maxSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxCur = max(maxCur + nums[i] , nums[i]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};
