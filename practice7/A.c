#include <stdio.h>
int main() {
    int a1, a2;
    int a[100], b[100];
    int n = 0, i;
    while (scanf("%dx%d%*[+]", a + n, b + n) > 0) n++;
    for (i = 0, a1 = a2 = 0; i < n; i++) {
        a1 += a[i];
        a2 += a[i] * b[i];
    }
    a1 -= a2;
    if (a1) printf("%d", a1);
    if (a1 && a2) putchar('+');
    if (a2) printf("%dx", a2);
    if (a1 || a2) putchar('+');
    printf("R(x)");
    return 0;
}
