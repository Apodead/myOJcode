#include<stdio.h>

long long a[10],ans;
int d,n;
int geta(int len){
    if(!a[len])
        for(int i=0;i<len;i++){
            a[len]=a[len]*10+d;
        }
    return a[len];
}
int main(){
    int i,tmp;
    scanf("%d%d",&d,&n);
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        ans+=geta (tmp);
    }
    printf("%lld",ans);
    return 0;
}
