
#include<bits/stdc++.h>
using namespace std;

/*
Counts number of set bits in each number
dp to store count upto curr maximum

Number of bits counted by Brian Kernighan’s Algorithm O(logn)

   1  Initialize count: = 0
   2  If integer n is not zero
      (a) Do bitwise & with (n-1) and assign the value back to n
          n: = n&(n-1)
      (b) Increment count by 1
      (c) go to step 2
   3  Else return count

Every time bitwise and with lower will flip rightmost set bit
Count number of these iterations

*/


class Solution {
public:
    unsigned int arr[100000];
    int curr=0;
    unsigned int countSetBits(int n)
    {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        
        if(curr>n){
            for(int i=0;i<=n;i++){
                ans.push_back(arr[i]);
            }
            
        }
        else{
            for(int i=0;i<=curr;i++){
                ans.push_back(arr[i]);
            }
            for(int i=curr+1;i<=n;i++){
                ans.push_back(countSetBits(i));
            }
            curr=n;
        }
        
        return ans;
    }
};