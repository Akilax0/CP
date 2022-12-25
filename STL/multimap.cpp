/**
 * Topic: multimap
 * 
 * Syntax : multimap<T1,T2> obj;
 * 
 * 1. Same as map but multiple keys
 * 2. sorted 
 * 3. count, find, contains, equal_range, lower_bound, upper_bound
 * 4. don;t have at() or [] to access elements
 * 
 * 
 * 
 * 
 * why? better than map<int,vector<int>> 
 * 
 * 
 * unorederd_multimap = maintain collection of duplicate kets for fast insertion and removal -> buckets and hashing
 * 
*/



//author: akilax0
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
ll MOD = 1000000000;
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
 

int main()
{

    multimap<char,int> Multm;
    Multm.insert(mp('a',1));
    Multm.insert(mp('a',2));
    Multm.insert(mp('a',3));
    Multm.insert(mp('b',4));
    Multm.insert(mp('b',5));
    
    //contains --> check if available
    //find --> returns something 
    

    for(auto&el1:Multm){
        cout<<el1.fi<<" "<<el1.se<<endl;
    }

    auto range = Multm.equal_range('a');
    for(auto it = range.fi; it!=range.se; ++it){
        cout<<it->fi<<" "<<it->se<<endl;
    }

    // returns first element 
    auto range = Multm.lower_bound('a');
    for(auto it = range.fi; it!=range.se; ++it){
        cout<<it->fi<<" "<<it->se<<endl;
    }

    // returns first element of next set 
    auto range = Multm.upper_bound('a');
    for(auto it = range.fi; it!=range.se; ++it){
        cout<<it->fi<<" "<<it->se<<endl;
    }


    return 0;
}