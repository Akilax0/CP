#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int max_cons = 0,curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr +=1;
                if(curr > max_cons){
                    max_cons = curr;
                }
            }else{
                curr = 0;
            }

        }
        return max_cons;
    }
};

int main(){

    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    
    int result = s.findMaxConsecutiveOnes(nums);
    cout<<result<<endl;
    return 0;
}
