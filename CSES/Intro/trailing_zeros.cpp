#include<bits/stdc++.h>


// checks  out how many times 10 appear
// by looking for number of prime factors {2,5}
// hence divide by 5


using namespace std;

int find_trail_zero(int n){
    
    if(n<0)
        return -1;

    int count = 0;

    for(int i=5;n/i>=1;i*=5){
        count += n/i;
    }

    return count;
    
}


int main(){
    int n;
    cin>>n;
    cout<<find_trail_zero(n)<<endl;

    return 0;
}
