#include<stdio.h>

int solveF(int n, int r){
    if(n<r)return 0;
    if(n==1||r==1||n==r)return 1;
    return solveF(n-1,r)*r+solveF(n-1,r-1);
}
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%d",solveF(n,r));
    return 0;
}
