#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result = nums;
        
        for(int i=0;i<nums.size();i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
int main(){

    Solution s;
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;
    vector<int> result = s.shuffle(nums,n);
    
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
