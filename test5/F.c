#include<stdio.h>

int main(){
    int x,y;
    long long sumx,sumy;
    sumx=sumy=0;
    while(scanf("%d%d",&x,&y)>0){
        if( x<=2000 && x>=1 &&
                y<=2000 && y>=1 &&
                (x%y) && (y%x) &&
                x!=1837 && y!=1837 )
            sumx+=x,sumy+=y;
    }
    printf("%lld %lld",sumx,sumy);
    return 0;
}

