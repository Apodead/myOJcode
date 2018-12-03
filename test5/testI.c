#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int n;
int  x,y;
double r,t,tt;
double _2pi;
char t1[255],t2[255];
int main(){
    int all,lost;
    scanf("%d",&n);
    all=n,lost=0;
    _2pi=acos(-1)*2;
    srand(time(NULL));
    while(n--){
        //scanf("%d%d",&x,&y);
        x=rand()+rand(),y=rand()+rand();
        r=sqrt((long long)x*x+(long long)y*y);
        tt=t=atan2(y,x);
        if(t<0){tt=t+2*M_PI;t+=_2pi;}
        sprintf(t1,"%.7lf",t);
        sprintf(t2,"%.7lf",tt);
        if(strcmp(t1,t2)){
            //printf("%.7lf %.20lf %.20lf\n",r,t,tt);
            //printf("%d %d\n",x,y);
            lost++;
        }
        //printf("%.7lf %.7lf\n",r,t);
    }
    printf("Wrong rate is %.3e in %d test.",(double)lost/all,all);
    return 0;
}

