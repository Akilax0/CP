#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;

    int arr[26];
    memset(arr,0,sizeof(arr));


    for(auto i:s){
        arr[i-'A']++;
    }

    int index = -1;
    int ct = 0;

    vector<char> front;
    vector<char> back;

    for(int i=0;i<26;i++){
        if(arr[i]%2!=0){
            index=i;
            ct++;
        }else{
            int tmp = arr[i]/2;
            for(int j=0;j<tmp;j++){
                front.push_back('A'+ i);
                back.push_back('A'+ i);
            }
        }
    }

    if(ct>1){
        cout<<"NO SOLUTION"<<endl;
    }else{
        for(auto i:front){
            cout<<i;
        }
        if(ct==1){
            for(int k=0;k<arr[index];k++){
                cout<<char(index+'A');
            }
        }
        sort(back.begin(),back.end(),greater<char>());
        for(auto i:back){
            cout<<i;
        }
    }

    return 0;
}
