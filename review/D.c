#include<stdio.h>
long long k,n,s,p;
int  main(){
    scanf("%lld%lld%lld%lld",&k,&n,&s,&p);
    long long t1=n/s+((n%s)?1:0);
    long long t2=t1*k;
    long long ans = t2 / p + ((t2 % p)? 1 : 0);
    printf("%lld",ans);
    return 0;
}
