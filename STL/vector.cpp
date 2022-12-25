/**
 * TOPIC : std::vector
 * 
 * 1. std::vector is a sequence container and also known as dynamic array -> data stored seq
 * 2. size can grow dynamically, no need to provide size at compile time
 * arr -> faster O(1), size known
 * vector -> faster + dymanic (linked list)
 * keeps doubling space and copy
 * 
 * Element access
 * at(),[],front(),back(),data() -> pointer return
 * 
 * 
 * Modifiers
 * insert(),emplace(),push_back(),emplace_back(),pop_back(), resize(),swap(),erase(),clear()
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
 

int main()
{
    v32 arr1;
    v32 arr2 (5,20); //size and init 
    v32 arr3 = {1,2,3,4,5,}; //init list
    v32 arr4 {1,2,3,4,5}; //uniform init

    arr2[3] = 10;
    arr2.at(3) = 10; //exception safe


    arr1.reserve(1000); // save allocation time
    arr1.resize(1000) ;
    return 0;
}