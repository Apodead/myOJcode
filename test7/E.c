#include <stdio.h>
const char chmap[20] = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
long long a, b, x;
char ans[100];
int len;
int main() {
    while (~scanf("%lld%lld%lld", &a, &b, &x)) {
        a = a + b;
        if (a == 0) putchar('0');
        for (len = 0; a; a /= x, len++) ans[len] = chmap[a % x];
        while (len--) putchar(ans[len]);
        putchar('\n');
    }
    return 0;
}