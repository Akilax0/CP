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
 

int result(char O, char M){
    if((O =='A' && M == 'X') || (O =='B' && M == 'Y') || (O =='C' && M == 'Z') ){
        return 3;
    }

    if((O =='C' && M == 'X') || (O =='A' && M == 'Y') || (O =='B' && M == 'Z') ){
        return 6;
    }

    return 0;
}

int choice(char M){

    if(M=='X')return 1;
    if(M=='Y')return 2;
    return 3;
}

char req(char O ,char M ){
    if(M=='Y'){
        if(O=='A')return 'X';
        if(O=='B')return 'Y';
        if(O=='C') return 'Z';
    }

    if(M=='X'){
        if(O=='A')return 'Z';
        if(O=='B')return 'X';
        if(O=='C') return 'Y';
    }


    if(M=='Z'){
        if(O=='A')return 'Y';
        if(O=='B')return 'Z';
        if(O=='C') return 'X';
    }
    
}

int main()
{
    char O,M,C;
    string line;
    fast_cin();
    ifstream file;
    file.open("input.txt");

    ll tot=0;

    if(file.is_open()){
        while(getline(file,line)){
            // cout<<line<<endl;
            O = line[0];
            M = line[2];
            // cout<<O<<" "<<M<<endl;

            C = req(O,M);

            // the output or req will be X,Y & Z
            tot += result(O,C) + choice(C);
        }
        file.close();
    } 

    cout<<tot<<endl;
    return 0;
}