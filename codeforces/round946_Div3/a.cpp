#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    // cout<<"Hello\n"<<endl;

    ll t;
    float a;
    float b;

    cin>> t ;

    while(t--){
        cin>>a>>b;

        if(b==0 && a!=0)
            cout<<ceil(a/15)<<endl;
        else if(b!=0 && a==0)  
            cout<<ceil(b/2)<<endl;
        else if((ceil(b/2)*15 - b*4) > a)
            cout<<ceil(b/2)<<endl;
        else
            cout<<ceil(b/2) + ceil((a-(ceil(b/2)*15-b*4))/15)<<endl;
         
        // cout<<b/2<<" "<<ceil(b/2)<<endl;
    }

	return 0;
}
