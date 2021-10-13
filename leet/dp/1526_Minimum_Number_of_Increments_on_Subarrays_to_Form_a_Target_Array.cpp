/**
 *
 *Given an array of positive integers target and an array initial of same size with all zeros.

Return the minimum number of operations to form a target array from initial if you are allowed to do the following operation:

Choose any subarray from initial and increment each value by one.
The answer is guaranteed to fit within the range of a 32-bit signed integer.
 *
 *
 * */


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        /**
        Whenever the current element a is bigger than the previous element,
we need at lease a - pre operations to make this difference.

We accumulate the total number of the operations,
this result is a lower bound and it's feasible.

        */
       
        
        
        int ans = 0;
        int pre =0;
        for(int i=0;i<target.size();i++){
            
            ans += max(target[i]-pre,0);
            pre = target[i];
                

        }
        
        return ans;
    }
};




