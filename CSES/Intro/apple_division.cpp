#include<bits/stdc++.h>
#include <numeric>

using namespace std;

void printVector(vector<int> v)
{
    // Print vector size
    cout << v.size() << endl;
 
    // Print vector elements
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    cout << endl;
}
 
// To divide n in two groups such that
// absolute difference of their sum is
// minimum
void findTwoGroup(int n, vector<int> apples)
{
    int sum = 0;
    sort(apples.begin(),apples.end(),greater<int>());

    // Find sum of all elements upto n
    for(auto i:apples)
        sum += i;
//    int sum = n * (n + 1) / 2;
   // cout<<"sum : "<<sum<<endl; 
    // Sum of elements of group1
    int group1Sum = sum / 2;
 
    vector<int> group1, group2;
 
    for (auto i:apples) {
 
        // If sum is greater then or equal
        // to 0 include i in group 1
        // otherwise include in group2
        if (group1Sum - i >= 0) {
 
            group1.push_back(i);
 
            // Decrease sum of group1
            group1Sum -= i;
        }
        else {
            group2.push_back(i);
        }
    }
    

    cout<<abs(accumulate(group1.begin(),group1.end(),0)-accumulate(group2.begin(),group2.end(),0))<<endl;
    // Print both the groups
//    printVector(group1);
//    printVector(group2);
}
 
int main(){


    int n;
    cin>>n;

    vector<int> apples;
    int a;
    for(int i=0;i<n;i++){

        cin>>a;
        apples.push_back(a);
    }

    findTwoGroup( n, apples) ;

    return 0;
}
