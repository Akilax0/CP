#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size()-1;i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }

    vector<int> twoSum_hash(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> numMap;
        for(int i=0;i<nums.size();i++){
            if (numMap.count(target-nums[i])>0){
                result.push_back(i);
                result.push_back(numMap[target-nums[i]]);
                return result;

            }
            numMap[nums[i]] = i;

            // for(int j = i+1;j<nums.size();j++){
            //     if(nums[i] + nums[j] == target){
            //         result.push_back(i);
            //         result.push_back(j);
            //         return result;
            //     }
            // }
        }
        return result;
    }
};


int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    // vector<int> result = s.twoSum(nums, target);
    vector<int> result = s.twoSum_hash(nums, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}

