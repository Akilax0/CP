#include<bits/stdc++.h>
#include <utility>

using namespace std;

vector<pair<int,int>> moves;

void hanoi(int n, int from, int to, int aux){
    if(n==0){
        return;
    }

    hanoi(n-1,from,aux,to);

    moves.push_back(make_pair(from, to));
//    cout<<from<<" "<<to<<endl;
    
    hanoi(n-1, aux,to,from);

}


int main(){
    int n;
    cin>>n;

    hanoi(n,1,3,2);
    
    cout<<moves.size()<<endl;
    for(auto i:moves){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}
