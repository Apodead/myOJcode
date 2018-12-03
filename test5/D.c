#include<stdio.h>

int main(){
    int n,i;
    int a[10];
    scanf("%d",&n);
    while(n--){
        for(i=0;i<5;i++)
            scanf("%d",a+i);
        for(i=4;i>=0;i--)
            printf("%+010d ",a[i]);
        putchar('\n');
    }
    return 0;
}

