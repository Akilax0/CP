#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int tot=0, single=0, db=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]/10 < 1){
                single += nums[i];
            }else if(nums[i]/100 < 1){
                db += nums[i];
            }

            tot += nums[i];
        }

        if((single < tot - single) || (db < tot - db)){
            return true;
        }
        return false;
    }
};
int main(){

    Solution s;
    vector<int> nums = {1,2,3,4,10};
    bool result = s.canAliceWin(nums);
    
    cout<<result<<endl;
    
    return 0;
}
