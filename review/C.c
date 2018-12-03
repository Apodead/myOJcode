#include<stdio.h>
char ch;
int sum;
int main(){
    sum=0;
    while(~(ch = getchar()))
        if(ch >= '0' && ch <= '9') sum += ch - '0';
    printf("%d",sum);
    return 0;
}

