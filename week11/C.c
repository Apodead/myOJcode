#include <stdio.h>
int t, n, m;
int f[105], g[105];
long long ans;
int main() {
    int i;
    int j, maxi;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < 100; i++) f[i] = g[i] = 0;
        for (i = 0; i < n; i++) scanf("%d", f + i);
        for (i = 0; i < m; i++) scanf("%d", g + i);
        for (i = 0, maxi = n + m - 1; i < maxi; i++) {
            for (ans = 0, j = 0; j < m && j <= i; j++) {
                if (i - j < n) ans += f[i - j] * g[j];
            }
            printf("%lld ", ans);
        }
        printf("\n");
    }
    return 0;
}
