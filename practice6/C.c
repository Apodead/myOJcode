#include <stdio.h>
#include <string.h>
int main() {
    char a[5005], b[5005];
    int lena, lenb, cmp;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s%s", a, b);
        if ((lena = strlen(a)) > (lenb = strlen(b)))
            printf("A\n");
        else if (strlen(a) < strlen(b))
            printf("B\n");
        else if ((cmp = strcmp(a, b))) {
            if (cmp > 0)
                printf("A\n");
            else
                printf("B\n");
        } else
            printf("EQUAL\n");
    }
}