#include<stdio.h>
int n,a;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        if(a>=85)
            putchar('A');
        else if(a >= 70)
            putchar('B');
        else if(a >= 60)
            putchar('C');
        else 
            putchar('D');
        if(n)
            putchar('\n');
    }
    return 0;
}
