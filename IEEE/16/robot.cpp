#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        
        int n;
        cin>>n;
        
        char a;
        vector<vector<char>> arr;
        
        for(int i=0;i<n;i++){
            vector<char> temp;
            for(int j=0;j<n;j++){
                cin>>a;
                temp.push_back(a);
            }
            arr.push_back(temp);
        }
        
        
        
        int m,c,b;
        cin>>m;
        
        vector<pair<int,int>> dust;
        for(int i=0;i<m;i++){
            cin>>c>>b;
            dust.push_back(make_pair(a,b));
        }
        
        int ans = 0;
        int k = 0;
    
        
        bool f = false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==dust[ans%m].first && j==dust[ans%m].second){
                    cout<< ans <<endl;
                    break;
                }
                
                
                if('>')j++;
                else if('v')i++;
                else if('<')j++;
                else if('^')j--;
                
                ans++;
                
            }
            if(f==false)break;
        }
        
    }
}