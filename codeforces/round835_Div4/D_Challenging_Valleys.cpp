#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,l,r,temp;
    cin>>t;
    
    while(t--){
        l=r=0;
        vector<int>arr;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            arr.push_back(a);
        }
        temp = arr[0];

        for(int i=0;i<n;i++){
            if(arr[i]==temp){
                r=i;
            }
        }

        cout<<"NO\n";


    }

    return 0;
}