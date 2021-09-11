#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[101];
    
    int getMaximumGenerated(int n) {
        
        if(n==0)return 0;
        else if(n==1)return 1;
        
        else{
             int nums[n+1];
        
        int ma = 1;
        
        nums[0]=0;
        nums[1]=1;
        
        for(int i=2;i<=n;i++){
            if(i%2==0){
                nums[i]=nums[i/2];
            }
            else{
                nums[i]=nums[(int)i/2] + nums[(int)i/2 + 1];
            }
            
            ma = max(nums[i],ma);
        }
        
        return ma;
        }
        
       
    }
};
