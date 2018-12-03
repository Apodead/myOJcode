#include<stdio.h>

int main(){
    double t;
    char mode;
    while(scanf("%lf%c",&t,&mode)>0){
        switch(mode){
            case 'C':
                if(t<-273.15){
                    printf("Out of Range\n");
                }else{
                t=9.0/5.0*t+32;
                printf("%.2lfF\n",t);
                }
                break;
            case 'F':
                t=5.0/9.0*(t-32);
                if(t<-273.15){
                    printf("Out of Range\n");
                }else
                    printf("%.2lfC\n",t);
        }
    }
    return 0;
}
