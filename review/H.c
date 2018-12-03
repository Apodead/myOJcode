#include<stdio.h>
int f2s(int hh,int mm,int ss){
    return hh*3600+mm*60+ss;
}
void ps2f(int s){
    printf("%d:%02d:%02d\n",s/3600,s%3600/60,s%60);
}
int main(){
    int a,b,c,d,h,m,s;
    while(scanf("%d:%d:%d",&h,&m,&s)>0){
        a=f2s(h,m,s);
        scanf("%d:%d:%d",&h,&m,&s);
        b=f2s(h,m,s);
        scanf("%d%d",&c,&d);
        a+=c;
        while(a>=b)b+=d;
        ps2f(b);
    }
    return 0;
}
    
