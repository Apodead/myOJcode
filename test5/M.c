#include<stdio.h>

void hanoi(int n,const char f,const char t,const char tmp){
    if(n==1)
        printf("%c --> %c\n",f,t);
    else{
        hanoi(n-1,f,tmp,t);
        printf("%c --> %c\n",f,t);
        hanoi(n-1,tmp,t,f);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    hanoi(n,'A','C','B');
    return 0;
}
