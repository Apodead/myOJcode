#include <stdio.h>
#define MAX 2005
int mat[MAX][MAX];
int m, n;
int readint() {
    char ch;
    int num = 0;
    while (((ch = getchar()) < '0' || ch > '9') && ch != '-')
        ;
    if (ch == '-')
        num = -(getchar() - '0');
    else
        num = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') num = num * 10 + ch - '0';
    return num;
}
int max[MAX], min[MAX], maxn, minn;
int i, j;
int cnt = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            mat[i][j] = readint();  // printf("%d\n", mat[i][j]);
    for (i = 0; i < n; i++)
        for (j = 1, maxn = mat[i][0], max[i] = 0; j < m; j++) {
            if (maxn < mat[i][j])
                maxn = mat[i][j], max[i] = j;
            else if (maxn == mat[i][j]) {
                max[i] = -1;
                break;
            }
        }
    for (i = 0; i < m; i++)
        for (j = 1, minn = mat[0][i], min[i] = 0; j < n; j++) {
            if (minn > mat[j][i])
                minn = mat[j][i], min[i] = j;
            else if (minn == mat[i][j]) {
                min[i] = -1;
                break;
            }
        }
    for (i = 0; i < n; i++)
        if (max[i] != -1 && min[max[i]] == i) cnt++;
    printf("%d\n", cnt);
    for (i = 0; i < n; i++)
        if (max[i] != -1 && min[max[i]] == i)
            printf("%d %d %d\n", i, max[i], mat[i][max[i]]);
    return 0;
}