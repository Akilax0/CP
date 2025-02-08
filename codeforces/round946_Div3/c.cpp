#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    ll t;

    ll a;
    ll b;

    cin>>t;

    while(t--){
        cin>>a;
        vector<ll> vec;
        for(int i=0;i<a;i++){
            cin>>b;
            vec.push_back(b);
        } 

        ll ans = 0;

        for (int i=0;i<a-2;i++){
            for (int j=i+1;j<a-2;j++){
                int temp = 0;
                if(abs(vec[i]-vec[j])!=0)
                    temp++;
                if(abs(vec[i+1]-vec[j+1])!=0)
                    temp++;
                if(abs(vec[i+2]-vec[j+2])!=0)
                    temp++;
                if(temp ==1)
                    ans++;
            }
        }

        cout<<ans<<endl;
        
    }
	return 0;
}
