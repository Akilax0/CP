/**
 *
 *
 *Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
 *
 *
 * */


class Solution {
public:
    
    int countVowelStrings(int n) {
        /**
            int k = number of vowels
            k=1 u
            k=2 o,u
            k=3 i,0,u
            k=4 e,i,o,u
            k=5 a,e,i,o,u
        */
        
        
        vector<vector<int>>dp(n + 1, vector<int>(6));
        
        for(int i=1;i<=n;i++){
            for(int k=1;k<=5;k++){
                dp[i][k] = dp[i][k-1] + (i>1?dp[i-1][k] : 1);
            }
            
        }
        
        
        return dp[n][5];   
    }
};
