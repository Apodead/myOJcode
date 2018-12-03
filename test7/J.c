#include <stdio.h>
#define MAX (int)1e5 + 5
int n, t, st;
int checked[MAX];
int cnt;
int i;
int main() {
    scanf("%d%d%d", &n, &st, &t);
    checked[st] = 1;
    for (i = 2; i <= t; i++) {
        st += i;
        if (st > n) st %= n;
        checked[st] = 1;
    }
    for (i = 1, st = 0, cnt = 0; i <= n; i++)
        if (!checked[i]) cnt++, st = 1;
    if (st) {
        printf("%d\n", cnt);
        for (i = 1; i <= n; i++) {
            if (!checked[i]) printf("%d ", i);
        }
    } else
        printf("have a pokemon");
}