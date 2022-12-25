/**
 * 
 * Topic: List
 * 
 * 1. double linked list
 * 2. Sequence container
 * 3. faster compared to other (vector, forward_list, deque)
 * insert,remove, and move in any position provided we have the iterator of the position 
 * 4. Should use instead traditional linked list
 *  a. Well tested
 *  b. Bunch of functions
 * 5. operator = , assign, front, back, empty , size, max_size, clear, insert, emplace, push_back, pop_back, push_front, pop_front, reverse, sort, merge, splice, unique,remove,
 * remove_if, resize
 * 
 * 
 * 
 * 
 * 
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
 

void solve(){
}
int main()
{
    
    list<int> list1 = {5,3,4,6,2};
    list<int> list2 = {7,6,1,9};


    for(auto& elm: list1){
        cout<<elm<<" ";
    }
    cout<<endl;

   for(auto& elm: list2){
        cout<<elm<<" ";
    }
    cout<<endl;

    //no back in forward_list
    // = simply replaces data 
    // list1 = list2 
    // list1 becomes list 2 values copied    
    
    return 0;
}