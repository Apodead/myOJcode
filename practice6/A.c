#include <stdio.h>
#define MAXN 1005
int main();
int t, m, n;
int f[MAXN], g[MAXN];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int i;
        for (i = 0; i < n; i++) scanf("%d", f + i);
        for (i = 0; i < m; i++) scanf("%d", g + i);
        int range = n + m - 1;
        long long yi, j;
        for (i = 0; i < range; i++) {
            for (yi = 0, j = 0; j < m; j++)
                if (i - j >= 0 && i - j < n) yi += f[i - j] * g[j];
            printf("%lld ", yi);
        }
        putchar('\n');
    }
}