#include<stdio.h>

//Taylor series expansion
//
//sin(x) = x - x^3/3! + x^5/5! ...
//
//where x (radians)
//
//180 deg = pi rad
//
//take pi = 3.14
//
//
//
//take angle in degrees
//
//inputs between[-180,180]

#define pi 3.14


double p(double,int);
long fac(int);

int main(){

    double sin;
    int n,deg;

    printf("Enter the angle (in degrees): ");
    scanf("%d",&deg);
    
    printf("Enter the number of iterations: ");
    scanf("%d",&n);

    // 180 deg = pi rad
    // 1 deg = pi/180 rad
    //
    // hence for x degrees
    // x deg = (x * pi)/180 rad
    //
  
    if(deg>180 || deg<-180){
        printf("Err: input an angle between -180 & 180\n");
        return 0;
    }
    
    double x = (deg * pi)/180;
 //   printf("%lf\n",x);

    for(int i=1;i<=n;i++){
        
        int c = 2*i-1;

        if(i%2!=0)
            sin = sin + p(x,c)/fac(c);
        else
            sin = sin - p(x,c)/fac(c);

//        printf("%0.6lf\t%0.6lf\n ",sin,p(x,c));
    }

    printf("The sin of %d is %.6lf\n",deg,sin);

    return 0;
}



double p(double x, int n){

    if(n==1)
        return x;

    return x*p(x,n-1);
}

long fac(int n){
    
    if(n==1)
        return 1;
    else
        return n * fac(n-1);
}
