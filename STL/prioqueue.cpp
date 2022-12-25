/**
 * Topic: priority_queue 
 * 
 * 
 * 
 * 0. container adapter constant time lookup for larget or smallest element
 * 1. default vector is container used
 * 2. Cost insertion and extraction log(n)
 * 3. priority_queue implemented using make_heap, push_heap, pop_heap
 * 
 * 
 * 
 * Min_Heap , Max_Heap
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
 

template<typename T> void print_queue(T& q){
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }

    cout<<'\n';
}
int main()
{
    {   
        priority_queue<int> q;
        for(int elm: {1,8,5,6,3,4,0,9,7,2}) {q.push(elm);}
        print_queue(q);
    }

    {   
        priority_queue<int,vector<int>,greater<int>> q2;
        for(int elm: {1,8,5,6,3,4,0,9,7,2}) {q2.push(elm);}
        print_queue(q2);
    }

    {   

        auto cmp = [](int left, int right){return (left) < (right);};
        priority_queue<int,vector<int>,decltype(cmp)> q3(cmp);
        for(int elm: {1,8,5,6,3,4,0,9,7,2}) {q3.push(elm);}
        print_queue(q3);
    }






    return 0;
}