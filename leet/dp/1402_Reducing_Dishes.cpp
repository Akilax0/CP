/**
 *
 *A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 
 * */



class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        
        sort(v.begin(),v.end());
        
        int ans=0;
        
        for(int i=0;i<v.size();i++){
            int temp=0;
            for(int j=i;j<v.size();j++){
                temp += v[j]*(j-i+1);
            }
            
            ans = max(ans,temp);
        }
        
        return ans;
    }
};



