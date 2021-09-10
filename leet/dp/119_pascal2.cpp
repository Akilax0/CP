#include<bits/stdc++.h>
using namespace std;


// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> r(rowIndex+1);

        for (int i = 0; i <=rowIndex; i++) {
            //resize row vector
            r[i].resize(i + 1);

            //assign 1 to start and end 
            r[i][0] = r[i][i] = 1;
  
            //in between calc from previous line
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r[rowIndex];
    }
};