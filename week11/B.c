#include <stdio.h>
char ans[] = ".7182818284";
int main() {
    int n;
    scanf("%d", &n);
    int i;
    if (n) {
        putchar('1');
        for (i = 0; i <= n; i++) putchar(ans[i]);
    } else
        putchar('2');
    return 0;
}
