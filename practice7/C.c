#include <math.h>
#include <stdio.h>
int main() {
    double n, m, a;
    scanf("%lf%lf%lf", &n, &m, &a);
    double x,xn,f;
    const double acc=1e-7;
    x=2.3456789;
    while(fabs(f=(pow(x,n)/m+cos(x)-a))>acc){
        x=x-f/(n*pow(x,n-1)/m-sin(x));
    }
    printf("%.8lf",x);
    return 0;
}