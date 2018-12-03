#include<stdio.h>
#include<math.h>
#define MAXX 110000

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

void solve(int a,int b)
{
    long long gc=gcd(a,b);
    long long xy=b*gc;
    long long x_y=sqrt(a*a-4.0*xy);
    long long x=(a+x_y)/2;
    long long y=a-x;
    long long tmp;
    if(x/gcd(x,y)*y!=b)
    {
        printf("No Solution\n");
        return;
    }
    if(x>y)tmp=x,x=y,y=tmp;
    printf("%lld %lld\n",x,y);
}

int main()
{
    long long a,b;
    while(~scanf("%lld%lld",&a,&b))
        solve(a,b);
    return 0;
}
