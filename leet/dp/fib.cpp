class Solution {
public:
    int arr[31];
    int curr =1;
    
    
    int fib(int n) {
        arr[0]=0;
        arr[1]=1;
    
        if(curr<n){
            for(int i=curr+1;i<=n;i++){
                arr[i] = arr[i-1]+arr[i-2];
            }
        }
        
        return arr[n];
    }
};