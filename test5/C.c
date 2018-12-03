#include<stdio.h>

int ans1[15]={ 0 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 ,  0};
int ans2[15]={ 0 , 1 , 1 , 1 , 0 , 1 , 0 , 1 , 1 ,  1};
int ans3[15]={0 , 1 , 1 , 1 , 0 , 0 , 0 , 1 , 0 ,  1};
int ans4[15]={ 0 , 0 , 1 , 1 , 1 , 0 , 0 , 1 , 1 ,  1};
int ans[15];
void dfs(int step){
    if(step==10){
        int i,g;
        for(g=0,i=0;i<10;i++)
            g+=ans[i]^ans1[i]?0:1;
        if(g!=7)return;
        for(g=0,i=0;i<10;i++)
            g+=ans[i]^ans2[i]?0:1;
        if(g!=5)return;
        for(g=0,i=0;i<10;i++)
            g+=ans[i]^ans3[i]?0:1;
        if(g!=3)return;
        for(i=0;i<10;i++)printf("%d ",ans[i]);
        for(g=0,i=0;i<10;i++)
            g+=ans[i]^ans4[i]?0:1;
        printf("\n%d",g*10);
        return;
    }
    ans[step]=0;
    dfs(step+1);
    ans[step]=1;
    dfs(step+1);
}

int main(){
    dfs(0);
    return 0;
}
