#include <stdio.h>
#include <string.h>
#define MAXN 1005
char a[MAXN], b[MAXN], c[MAXN];
int main() {
    int i, j;
    int la, lb, last;
    scanf("%s%s%s", a, b, c);
    la = strlen(a);
    lb = strlen(b);
    la = la - lb + 1;
    for (i = 0, last = 0; i < la;) {
        for (j = 0; j < lb && a[i + j] == b[j]; j++)
            ;
        if (j == lb) {
            a[i] = '\0';
            printf("%s%s", a + last, c);
            last = i += j;
        } else
            i++;
    }
    printf("%s", a + last);
    return 0;
}