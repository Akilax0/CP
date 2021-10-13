/**
 *
 *You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.
 * */



class Solution {
public:
    int numSplits(string s) {
        
        int ans = 0;
        
        map<char,int> count;
        
        set<int> left;
        set<int> right;
        
        if(s.size()==0)return 0;
        
        for(int i=0;i<s.size();i++){
            if(count.find(s[i])!=count.end()){
                count[s[i]] ++;
            }
            else{
                count[s[i]] = 1;
            }          
            
            right.insert(s[i]);
        }
        
        
        
        for(int j=0;j<s.size();j++){
        
            if(count[s[j]]==0){
                left.insert(s[j]);
            }
            else{
                count[s[j]]--;
                if(count[s[j]]==0)
                    right.erase(s[j]);
                    left.insert(s[j]);
            }
            
            if(left.size()==right.size())
                ans++;
        }
        return ans;
    }
};
