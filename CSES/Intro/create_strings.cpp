#include<bits/stdc++.h>

using namespace std;

int main(){
    
    string s;
    cin>>s;

    vector<string> ss;
    std::sort(s.begin(), s.end());
    do {
//        std::cout << s << '\n';
        ss.push_back(s);
    } while(std::next_permutation(s.begin(), s.end()));


    cout<<ss.size()<<endl;

    for(auto i:ss){
        cout<<i<<endl;
    }
    return 0;
}
