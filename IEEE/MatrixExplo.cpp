#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k,a,b;
    cin >> n >> m >> k;
    int arr[n][m];
    
    char t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>t;
            if(t=='.')
                arr[i][j]=numeric_limits<int>::max();;
            else
                arr[i][j]=-1;
        }
    }
    
    vector<pair<int,int>> pos;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        
        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        
        queue<pair<int,int>> q;
        
        q.push(make_tuple(a-1,b-1,0));
        
        while(!q.empty()){
            tuple<a,b> u = q.front();
            q.pop();
            
            u_x = get<0>(u);
            u_y = get<1>(u);
            u_d = get<2>(u);
            
            if(arr[u_x][u_y]>u_d){
                arr[u_x][u_y] = u_d;
            }
            
            visited[u_x][u_y]= true;
            
            if(u_x-1 >=0 && !visited[u_x-1][u_y] && arr[u_x-1][u_y]!=-1){
                q.push(make(tuple(u_x-1,u_y,u_d+1)));
            }
            if(u_y-1 >=0 && !visited[u_x][u_y-1] && arr[u_x][u_y-1]!=-1){
                q.push(make(tuple(u_x,u_y-1,u_d+1)));
            }
            if(u_x+1 < n && !visited[u_x+1][u_y] && arr[u_x+1][u_y]!=-1){
                q.push(make(tuple(u_x+1,u_y,u_d+1)));
            }
            if(u_y +1 < m && !visited[u_x][u_y+1] && arr[u_x][u_y+1]!=-1){
                q.push(make(tuple(u_x,u_y+1,u_d+1)));
            }
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=-1)
                ans += arr[i][j];
        }
    }
    
    
    return 0;
}
