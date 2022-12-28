#include <cstring>
#include <utility>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32; typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

/*
string del=" ";
size_t pos = 0;
string tok;
while ((pos = line.find(del)) != std::string::npos) {
    tok = line.substr(0, pos);
    if(i%2==0){
        arr[(i-2)/2] = stoi(tok);
    }
    i++;
    line.erase(0, pos + del.length());
}

*/


map<string,vector<string>> tree;
map<string,int> s;

void bfs(pair<string,int>ss){
    if(s.find(ss.first)==s.end()){
        //cout<<ss.first<<" "<<ss.second<<endl; 
        cout<<ss.first<<": ";
        for(auto j: tree[ss.first]){
            cout<<j<<endl; 
            if(s.find(j)==s.end()){
                bfs(make_pair(j,0));
            }
            ss.second += s[j];
        }
        cout<<endl;

        s.insert({ss.first,ss.second});
    }
}



int main()
{
    string line;
    fast_cin();
    ifstream file;

    file.open("input.txt");

    bool ls=false;
    
    map<string,string> parent;
    string dir;
    if(file.is_open()){
        while(getline(file,line)){
            if(ls){
                ls = false;
                continue;
            }
            //cout<<line<<endl;
            if(line[0]=='$'){
                //cout<<line.substr(2,2)<<" ";
                if(line.substr(2,2)=="cd"){
                    string out =  line.substr(5,line.length()-5);       
                 //   cout<<"Change into dir:"<<dir;
                    if(out!=".."){
                        ls = true;
                        dir = out;
                    }else{
                        dir = parent[dir];
                    }
                }
            }
            else if(line.substr(0,3)=="dir"){
                //cout<<"found directory: "<<line.substr(3,line.length()-3);
                string fold = line.substr(4,line.length()-4);
                tree[dir].push_back(fold);
                parent.insert({fold,dir});
                
            }
            else{
                string del=" ";
                size_t pos = 0;
                int size;
                string file;
                string tok;
                while ((pos = line.find(del)) != std::string::npos) {
                    tok = line.substr(0, pos);
                    size = stoi(tok);
                    line.erase(0, pos + del.length());
                }
                file = line;
                //cout<< "file  with name: "<<file<<" & size: "<<size;
                tree[dir].push_back(file);
                parent.insert({file,dir});
                s.insert({file,size});

            }
            //cout<<endl;
        }

        file.close();

        
        cout<<"Tree: "<<endl;
        for(auto i:tree){
            cout<<i.first<<": ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        bfs(make_pair("/",0));
        cout<<"Sizes: "<<endl;
        for(auto i:s){
            cout<<i.first<<": "<<i.second<<endl;
        }


        ll tot=0;
        for(auto i: tree){
            if(s[i.first]<100000){
                tot +=s[i.first];
            }
        }
        cout<<tot<<endl;
        
    }

    return 0;
}
