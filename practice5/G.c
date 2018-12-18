#include <stdio.h>

int n, a, b;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
    scanf("%d", &n);
    for (a = n / 2, b = n - a; a && gcd(a, b) != 1; a--, b++)
        ;
    printf("%d %d", a, b);
    return 0;
}
