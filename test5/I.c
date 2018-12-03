#include<stdio.h>
#include<math.h>

int n;
int  x,y;
double r,t;
double _2pi;
int main(){
    scanf("%d",&n);
    _2pi=acos(-1);
    while(n--){
        scanf("%d%d",&x,&y);
        r=sqrt((long long)x*x+(long long)y*y);
        t=atan2(y,x);
        if(t<0)t+=_2pi;
        printf("%.7lf %.7lf\n",r,t);
    }
    return 0;
}

