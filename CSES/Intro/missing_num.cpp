#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,a;
    ll m=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a;
        m+=a;
    }
 
    cout<<(ll)((n*(n+1))/2LL)-m<<"\n";
    return 0;
}
