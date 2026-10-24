#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;

        unordered_map<int,int> ma;

        int tot = 0;
        int expected_tot = (nums.size() * (nums.size()+1))/2;

        for(int i=0;i<nums.size();i++){
            if(ma.find(nums[i])!= ma.end()){
                ma[nums[i]] += 1;
                result.push_back(nums[i]);
            }
            else{
                ma[nums[i]] = 0;
            }
            tot += nums[i];
        }

        expected_tot -= tot;

        result.push_back(result[0]+expected_tot);
        return result;

        // for(int i=0;i<nums.size();i++){
        //     if(ma.find(i+1)==ma.end()){
        //         result.push_back(i+1);
        //         return result;
        //     }
        // }


        return result;
    }
};
int main(){

    Solution s;
    vector<int> nums = {1,2,2,4};
    vector<int> result = s.findErrorNums(nums);
    
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
