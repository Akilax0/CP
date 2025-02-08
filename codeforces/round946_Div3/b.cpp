#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    ll t;

    ll a;
    string b;

    cin>>t;

    while(t--){
        cin>>a;
        cin>>b;

        string c = b;

        string code = "";

        sort(c.begin(),c.end());

        
        char d = c[0];
        code = code + d;

        for(int i=1; i<c.length();i++){
            if (d!=c[i]){
                d = c[i];
                code = code + d; 
            }
        } 

        ll temp = code.length();
        
        for (int j=0;j<b.length();j++){
            for (int k = 0 ;k<temp;k++){
                if(code[k]==b[j]){
                    b[j]=code[temp-k-1];
                    break;
                }
            }
        }
        cout<<b<<endl;
    }
	return 0;
}
