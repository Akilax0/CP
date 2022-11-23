#include<bits/stdc++.h>

using namespace std;

int main(){

    int t,n,m;
    cin>>t;
    string s;
    while(t--){
        
        m = 0;
        cin>>n>>s;

        for(auto i:s) {
            m = max(m, i-'a'+1);
        }

        cout<<m<<endl;
    }

    return 0;
}