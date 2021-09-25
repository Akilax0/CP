/**
 *The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.


 *
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 * */





class Solution {
public:
    
        map<int,int> m;
    
    
    int power(int n){
        int key = n;
        int ct = 0;
        
        while(n!=1){
            if ( m.find(n) == m.end() ) {
                n = n%2==0 ? n/2: n*3+1; 
                ct++;
            } else {
                return ct + m[n];
            }            
        }   
        
        m[key] = ct;
        return ct;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> arr;
        
        for(int i=lo;i<=hi;i++){
            arr.push_back(make_pair(i,0));
        }
        
        for(int i=0;i<arr.size();i++){      
            arr[i].second = power(arr[i].first);
        }
        
        std::sort(arr.begin(), arr.end(), [](auto &left, auto &right) {
            return (left.second==right.second)?(left.first<right.first) : left.second < right.second;
        });
        
//     for(int i=0;i<arr.size();i++){
//         cout<<arr[i].first<<" "<<arr[i].second<<endl;
//     }
        
        return arr[k-1].first;
    }
};
