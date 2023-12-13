#include<bits/stdc++.h>


//  example takes x times 2a + b
// and y times 2b+a
// gives equations 
// 2x + y = a
// 2y + x = b

// Solving we get
// 2a-b = 3x
// 2b -a = 3y


//  example takes x times 2a + b
// and y times 2b+a
// gives equations 
// 2x + y = a
// 2y + x = b

// Solving we get
// 2a-b = 3x
// 2b -a = 3y


// Hence 3x and 3y should be non negative
// and divisible by 3

#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;

    ll a,b;
    while(t--){
        cin>>a>>b;
        if((2*a-b)%3==0 && (2*a-b)>=0 && (2*b-a)>=0 &&(2*b-a)%3==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;

}
