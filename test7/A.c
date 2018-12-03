#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int n, num[1005];
int main() {
    int i;
    int now, cnt, ans;
    while (~scanf("%d", &n)) {
        for (i = 0; i < n; i++) scanf("%d", num + i);
        qsort(num, n, sizeof(int), cmp);
        for (cnt = ans = 0, now = num[0], i = 0; i < n; i++) {
            if (now != num[i])
                ans = (cnt > ans ? cnt : ans), cnt = 0, now = num[i];
            cnt++;
        }
        if (now != num[i]) ans = (cnt > ans ? cnt : ans), cnt = 0, now = num[i];
        printf("%d\n",ans);
    }
    return 0;
}