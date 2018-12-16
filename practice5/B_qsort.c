#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    long long result = *(long long *)a - *(long long *)b;
    if (result > 0)
        return 1;
    else if (result == 0)
        return 0;
    else
        return -1;
}
int n, i;
long long ansn, ans;
long long num[100005];
long long buf[100005];
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lld", num + i);
    qsort(num, n, sizeof(long long), cmp);
    for (i = 1, ansn = num[0], ans = num[1] - num[0]; i < n - 1; i++) {
        if (num[i + 1] - num[i] < ans) ans = num[i + 1] - num[i], ansn = num[i];
    }
    printf("%lld %lld", ansn, ans + ansn);
    return 0;
}
