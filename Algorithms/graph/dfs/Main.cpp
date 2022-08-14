#include<bits/stdc++.h>
#define pb push_back

using namespace std;


vector<bool>v;
vector<vector<int> > g;

void edge(int a,int b){
    g[a].pb(b);

    //for undirected graph 
    // g[b].pb(a);
}

void dfs(int u){
   
    v[u] = true;
    cout<< u << " ";

   //iterate through all neighbours
    for(auto i=g[u].begin();i!=g[u].end();i++){
        if(!v[*i]){
            dfs(*i);
        }
    }
    
}


int main(){

/*Input:

4 6
0 1
0 2
1 2
2 0
2 3
3 3


Output:
2 0 1 3

*/


    int n, e;
    cin >> n >> e;
 
    v.assign(n, false);
    g.assign(n, vector<int>());
 
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edge(a, b);
    }
 
 
    //starting from node 2
    dfs(2);
    

    return 0;
}