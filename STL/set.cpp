/**
 * Topic: std::set<T>
 * 
 * Syntax: std::set<T> objectName;
 * 
 * 1.std::set is an Associative Container that contains sorted set of uniques objects of type Key  
 * associative container -> set,multiset,map,multimap // associates element to something
 * 2. usually red-black tree
 * 3. insertion, removal, search log(n)
 * 4. If user defined data type have to provide comp func
 * 5. can pass order of sorting while constructing set
 * 
 * 
 * stores elements in sorted order
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
 
class Person{

    public:
        float age;
        string name;

    bool operator < (const Person& rhs) const {return age<rhs.age;}
    bool operator > (const Person& rhs) const {return age>rhs.age;}
};


void solve(){
}
int main()
{
    set<Person> Sett = {{30,"das"},{12,"asd"},{32,"fasd"}};
    set<Person,std::greater<>> Setto = {{30,"das"},{12,"asd"},{32,"fasd"}};
    set<int> Set={1,2,3,4,5,1,2,3,4,5};

    // <int,std::greater> || <int,std::less>
    for(const auto& e:Setto){
        cout<<e.age << " " << e.name<<endl;
    }
    
    return 0;
}