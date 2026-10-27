#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0,tot=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')
                r++;
            else
                l++;

            if(l==r){
                tot++;
                l=0;
                r=0;
            }
        }

        return tot;
    }
};
int main(){

    Solution s;
    string bs = "RLRRLLRLRL";
    int result = s.balancedStringSplit(bs);
    cout << result << endl;
    return 0;
}
