#include <stdio.h>
long long it, n, a[60];
int main() {
    scanf("%lld", &n);
    int i;
    for (i = 0; i < n; i++) scanf("%lld", a + i);
    int range = 1 << (n );
    long long sum = 0;
    for (it = 0; it < range; it++) {
        long long wei = 1;
        for (i = 0; i < n; i++)
            if (it & (1 << i)) wei *= a[i];
        sum += wei;
    }
    printf("%lld", sum);
    return 0;
}