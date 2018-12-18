#include <stdio.h>

int n, a[1005];
int main() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    i = n % 2 ? n : n - 1;
    for (; i > 0; i -= 2) printf("%d ", a[i]);
    for (i = 2; i <= n; i += 2) printf("%d ", a[i]);
    return 0;
}
