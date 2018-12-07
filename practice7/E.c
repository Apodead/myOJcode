#include <stdio.h>
int mat[505][505];
int x, y, n;
int i, j;
int remain;
int step = 1;
int main() {
    scanf("%d", &n);
    y = n / 2 + 1, x = n;
    remain = n * n;
    while (remain--) {
        if (mat[x][y]) x = (x -= 2) > 0 ? x : n, y = --y ? y : n;
        mat[x][y] = step++;
        if (x == n && y == n)
            x = n - 1;
        else
            x++, y++;
        if (x > n) x %= n;
        if (y > n) y %= n;
    }
    for (i = 1; i <= n; i++, putchar('\n'))
        for (j = 1; j <= n; j++) printf("%d ", mat[i][j]);
    return 0;
}