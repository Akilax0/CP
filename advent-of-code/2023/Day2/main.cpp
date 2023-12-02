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

 
    if(file.is_open()){
        ll tot = 0;
        int r = 12;
        int g = 13;
        int b = 14;
        int num = 0;

        // for minimum possible 
        // int rr = 0;
        // int gg = 0;
        // int bb = 0;
       
        while(getline(file,line)){
            int rr = 0;
            int gg = 0;
            int bb = 0;
            bool f = true;
            // cout<<line<<endl;
            //s.find(words)
            
            string a = "";
            for(char& c: line){

                
                if((c-':')==0){
                    num = stoi(a.substr(5));
                    cout<<"Game : "<<num<<endl;
                    a = "";
                } 

                if((c-';')==0){
                    string aa = "";
                    int nn = 0;
                    for(char& cc:a){
                        aa += cc;

                        if((cc-'0')<10 && (cc-'0')>=0){
                            nn = nn*10+(cc-'0');
                            
                        }
                        if(aa.find("red")!=string::npos){
                            cout<<"red"<<nn<<endl;
                            
                                rr = max(nn,rr);
                            
                            aa = "";
                            nn = 0;
                        }
                        if(aa.find("blue")!=string::npos){
                            cout<<"blue"<<nn<<endl;
                            
                                bb = max(nn,bb);
                            
                            aa = "";
                            nn = 0;
                        }
                        if(aa.find("green")!=string::npos){
                            cout<<"green"<<nn<<endl;
                           
                                gg = max(nn,gg);
                            
                            aa = "";
                            nn = 0;
                        }

                        
                    }

                    if (f==false)
                        break;
                    a = "";
                }

                a += c;

                
            }

             string aa = "";
             int nn = 0;
                    for(char& cc:a){
                        aa += cc;
                         if((cc-'0')<10 && (cc-'0')>=0){
                            nn = nn*10+(cc-'0');
                            
                        }
                        if(aa.find("red")!=string::npos){
                            cout<<"red"<<nn<<endl;
                           
                                rr = max(nn,rr);
                            
                            aa = "";
                            nn = 0;
                        }
                        if(aa.find("blue")!=string::npos){
                            cout<<"blue"<<nn<<endl;
                          
                                bb = max(nn,bb);
                            
                            aa = "";
                            nn = 0;
                        }
                        if(aa.find("green")!=string::npos){
                            cout<<"green"<<nn<<endl;
                            gg = max(nn,gg);
                            
                            aa = "";
                            nn=0;
                        }
                    }

            cout<<(rr*bb*gg)<<endl;
            tot = tot + (rr*bb*gg); 
            
        }
        
        cout<<tot<<endl;
        file.close();
    } 

    
    
    return 0;
}