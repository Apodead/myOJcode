#include <stdio.h>

int a[105], b[105], tmp[105];
int ch;
void readint(int *a) {
    while ((ch = getchar()) < '0' || ch > '9')
        ;
    tmp[0] = 1, tmp[1] = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') tmp[++tmp[0]] = ch - '0';
    while (tmp[0]) a[++a[0]] = tmp[tmp[0]--];
}
int main() {
    readint(a);
    readint(b);

    return 0;
}
