#include <stdio.h>

int main(){
    int l,r,i;
    scanf("%d%d",&l,&r);
    for(i=l;i<=r;i++){
        switch(i%10){
            case 1:
            case 8:
            case 7:
            case 3:
                printf("%d\n",i);
        }
    }
    return 0;
}
