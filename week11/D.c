#include <stdio.h>
char ch[1005];
int i, j, n, len;
int main() {
    int l, r;
    char tmp;
    while ((ch[len] = getchar()) != '\n') len++;
    ch[len] = '\0';
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        while (l < r) {
            tmp = ch[l];
            ch[l] = ch[r];
            ch[r] = tmp;
            l++, r--;
        }
    }
    printf("%s", ch);
}