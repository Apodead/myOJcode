#include <stdio.h>

int main() {
    double ans = 0;
    long long fac = 1, acc = 10;
    char fmt[15];
    int n, step;
    scanf("%d", &n);
    step = n;
    while (step--) acc *= 10;
    for (step = 2; fac <= acc; step++) {
        ans += 1.0 / fac;
        fac *= step;
    }
    sprintf(fmt, "%%.%dlf", n);
    if (n)
        printf(fmt, ans);
    else
        printf("2");
    /*
    printf("2");
    if(n>0){
        printf(".");
        step=n;
        while(step--){
            printf("%d",(int)ans);
            ans-=(int)ans;
            ans*=10;
        }
    }
    */
    return 0;
}

