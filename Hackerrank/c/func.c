#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max(int a,int b){
    if(a>=b)return a;
    return b;
}


int max_of_four(int a,int b,int c,int d){
    int m;
    m = max(a,b);
    m = max(m,c);
    m = max(m,d);
    
    return m;
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
