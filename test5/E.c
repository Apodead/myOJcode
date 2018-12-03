#include<stdio.h>

void solve(){
    int num;
    if(scanf("%d",&num)>0)
        solve();
    else
        return;
    printf("%d\n",num);
}
int main(){
    solve();
    return 0;
}
