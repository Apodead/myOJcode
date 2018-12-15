#include<stdio.h>
int n;
int in[105];
long long f[500005];
int i,j;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",in+i),j=in[i]>j?in[i]:j;
    for(f[1]=f[2]=f[3]=1,i=4;i<=j;i++)
        f[i]=f[i-2]+f[i-3],f[i]%=100000007;
    for(i=0;i<n;i++)
        printf("%lld\n",f[in[i]]);
    return 0;
}
