/**
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

	A subsequence of a string is a new string that is formed from the original string 
	by deleting some (can be none) of the characters without disturbing the relative 
	positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

*/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)return true;
        
        int s_i = 0;
        
        for(int i=0;i<t.length();i++){
            if(s[s_i]==t[i])
                s_i++;
            if(s_i==s.length())
                return true;
        }
        
        return s_i==s.length();
    }
};
