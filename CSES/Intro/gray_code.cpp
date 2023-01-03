#include<bits/stdc++.h>


using namespace std;


void gray_code(int n){
        
    for(int i=0;i<(1<<n);i++){
        
        // generating gray code 
        int val = (i ^ (i>>1));
        
//        cout<<val<<endl;
        bitset<32> r(val);

        string s = r.to_string();
        cout<<s.substr(32-n) <<endl;
    //
    }
}

int main(){
    
    int n;
    cin>>n;
    
    gray_code(n);


    return 0;
}
