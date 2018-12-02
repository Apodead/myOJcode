#include<stdio.h>
int main(){
    int n;
    int a[15],b[15];
    int i,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(i=0;i<n;i++){
        scanf("%d",b+i);
    }
    for(i=0,sum=0;i<n;i++)
        sum+=a[i]*b[i];
    printf("%d",sum);
    return 0;
}
