#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,a,b,k;
    cin>>t;
    while(t--){
        vector<int>arr;
        vector<int> s;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>k;
            s.push_back(k);
            arr.push_back(k);
        }

        sort(s.begin(),s.end());
        a = s[n-1];
        b = s[n-2];

        for(int i=0;i<n;i++){
            if(arr[i]!=a){
                cout<<arr[i]-a<<" ";
            }else{
                cout<<arr[i]-b<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}