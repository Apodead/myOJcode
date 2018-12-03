#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=-1){
        int buf[n],foo[n];
        for(int i=0;i<n;i++){
            printf("%p:%d,size:%lu\n",buf+i,buf[n],sizeof(buf[n]));
            printf("%p:%d,size:%lu\n",foo+i,foo[n],sizeof(foo[n]));
        }
    }
    return 0;
}

