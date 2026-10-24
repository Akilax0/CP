#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>res(nums.size()*2);
        for(int i=0;i<nums.size();i++){
            res[i] = nums[i];
            res[i+nums.size()] = nums[i];
        }

        return res;
    }
};
int main(){

    Solution s;
    vector<int> nums = {2,5,1,3,4,7};
    vector<int> result = s.getConcatenation(nums);
    
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
