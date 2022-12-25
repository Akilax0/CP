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
    int arr[4];
    memset(arr,0,sizeof(arr));


    vector<string> pair;
    string del=",";
    size_t pos = 0;
    string tok;
    while ((pos = line.find(del)) != std::string::npos) {
        tok = line.substr(0, pos);
        pair.pb(tok); 
        line.erase(0, pos + del.length());
    }
    pair.pb(line);
    
    int i=0;
    for(auto s: pair){
        del="-";
        pos = 0;
        while ((pos = s.find(del)) != std::string::npos) {
            tok = s.substr(0, pos);
            arr[i]=stoi(tok);
            i++; 
            s.erase(0, pos + del.length());
        }
        arr[i]=stoi(s);
        i++;
    }
   
    // for(auto j: arr){
    //     cout<<j<<" ";
    // }

    if((arr[0]<=arr[2] && arr[1]>=arr[2]) || (arr[0]<=arr[3] && arr[1]>=arr[3])|| (arr[2]<=arr[0] && arr[3]>=arr[0])|| (arr[2]<=arr[1] && arr[3]>=arr[1]) )
        return 1;

    return 0;
}

int main()
{

//    memset(check, 0, sizeof(check));

    string line;
    fast_cin();
    ifstream file;
    file.open("input.txt");

    int tot=0;

    if(file.is_open()){
        while(getline(file,line)){
        
            //cout<<line<<endl;

           tot+= calc(line);
        }
        file.close();
    }

    cout<<tot<<endl; 
    return 0;
}
