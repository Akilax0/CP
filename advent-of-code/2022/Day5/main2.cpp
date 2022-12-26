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
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
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
 



int calc(string line){
    return 0;
}

int main()
{

    vector<vector<char>> stacks(9);

    stacks[0] = {'R','N','P','G'};
    stacks[1] = {'T','J','B','L','C','S','V','H'};
    stacks[2] = {'T','D','B','M','N','L'};
    stacks[3] = {'R','V','P','S','B'};
    stacks[4] = {'G','C','Q','S','W','M','V','H'};
    stacks[5] = {'W','Q','S','C','D','B','J'};
    stacks[6] = {'F','Q','L'};
    stacks[7] = {'W','M','H','T','D','L','F','V'};
    stacks[8] = {'L','P','B','V','M','J','F'};

    string line;
    fast_cin();
    ifstream file;



    file.open("input.txt");

    int arr[3];
    if(file.is_open()){
        while(getline(file,line)){
        
//            cout<<line<<endl;
            int i=1;
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
            arr[2] = stoi(line);
            

            for(int i=0;i<3;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
    
            for(auto k:stacks[arr[1]-1]){
                cout<<k<<" ";                  
            }
            cout<<endl;
            for(auto k:stacks[arr[2]-1]){
                cout<<k<<" ";                  
            }
            
            cout<<endl;
            cout<<endl;

            vector<char> subvector = {stacks[arr[1]-1].end() - arr[0], stacks[arr[1]-1].end()};
            stacks[arr[1]-1].erase(stacks[arr[1]-1].end() - arr[0], stacks[arr[1]-1].end());
            stacks[arr[2]-1].insert(stacks[arr[2]-1].end(),subvector.begin(),subvector.end());
            
            for(auto k:stacks[arr[1]-1]){
                cout<<k<<" ";                  
            }
            cout<<endl;
            for(auto j:subvector){
                cout<<j<<" ";
            }
            cout<<endl;
            for(auto k:stacks[arr[2]-1]){
                cout<<k<<" ";                  
            }
            cout<<endl;
/*
            for(int j=0;j<arr[0];j++){
                stacks[arr[2]-1].push_back(stacks[arr[1]-1].back());
                stacks[arr[1]-1].pop_back();
            }
*/          
        }
        file.close();
    }

    for(int i=0;i<9;i++){
        if(stacks[i].empty()){
            cout<< "empty" << " ";
        }
        else {
            cout<<stacks[i].back()<<" ";
        }
    }
    return 0;
}
