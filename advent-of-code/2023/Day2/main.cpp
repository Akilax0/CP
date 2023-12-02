#include<bits/stdc++.h>
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
    char O,M;
    string line;
    // fast_cin();
    ifstream file;
    file.open("input.txt");

    string snum[9] = {"one","two","three","four","five","six","seven","eight","nine"};

    if(file.is_open()){
        ll tot = 0;
        int ct = 1;

        while(getline(file,line)){
            // cout<<line<<endl;
            //s.find(words)
            vector<int> nums;
            vector<int> rnums;
            

            string a = "";
            cout<<"count:"<<ct<<endl;
            
            for (char& c :  line){
                
                
                if ((c-'0') < 10){
                    nums.push_back(c-'0');
                    a = "";
                    // cout<<"cleared"<<endl;
                }
                else{
                    a += c;
                    

                    for(int i=1;i<=9;i++){
                        if(a.find(snum[i-1])!= string::npos){
                            cout<<"word:"<<a<<endl;
                            a = "";
                            nums.push_back(i);
                            break;
                        }
                    }
                }

                  
            }

                 for(int i=1;i<=9;i++){
                        if(a.find(snum[i-1])!= string::npos){
                            cout<<"word:"<<a<<endl;
                            a = "";
                            nums.push_back(i);
                            break;
                        }
                    }

            ct++;  
            // cout << nums[0]*10+nums.back() << endl;
            a = "";
            reverse(line.begin(),line.end());

            for (char& c :  line){
                
                
                if ((c-'0') < 10){
                    rnums.push_back(c-'0');
                    a = "";
                    // cout<<"cleared"<<endl;
                }
                else{
                    a = c + a;
                    

                    for(int i=1;i<=9;i++){
                        if(a.find(snum[i-1])!= string::npos){
                            cout<<"word:"<<a<<endl;
                            a = "";
                            rnums.push_back(i);
                            break;
                        }
                    }
                }

                  
            }

            for(int i=1;i<=9;i++){
                if(a.find(snum[i-1])!= string::npos){
                    cout<<"word:"<<a<<endl;
                    a = "";
                    rnums.push_back(i);
                    break;
                }
            }
        

            tot = tot + (nums[0]*10+rnums[0]);
        }
        cout<<tot<<endl;
        file.close();
    } 

    
    
    return 0;
}