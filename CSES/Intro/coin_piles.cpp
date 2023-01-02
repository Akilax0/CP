#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;

    ll a,b;

    ll a_p,b_p;
    while(t--){
        cin>>a>>b;

        if(a==0 && b==0){
            cout<<"YES\n";
            continue;
        }
        else if(a==0 || b==0){
            cout<<"NO\n";
            continue;
        }

    while(a!=0 && b!=0){
        a_p = a/2;
        a = a - 2*a_p;
        b = b - a_p;


        b_p = b/2;
        b = b - 2*b_p;
        a = a - b_p;
    }
        
        if(a==0 and b==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;

}
