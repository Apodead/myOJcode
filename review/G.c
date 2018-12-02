#include<stdio.h>
#include<math.h>
double l,r,m,y;
const double acc=1e-8;
double f(double x){return 2*sin(x)+sin(2*x)+sin(3*x)+(x-1)*(x-1);}
int main(){
    while(scanf("%lf",&y)>0){
        l=4,r=8;
        if((f(l)-y)*(f(r)-y)>0){
            printf("No solution!\n");
            continue;
        }
        while(r-l>acc){
            m=(l+r)/2;
            if((f(l)-y)*(f(m)-y)<0)
                r=m;
            else
                l=m;
        }
        printf("%.6lf\n",(r+l)/2);
    }
    return 0;
}

