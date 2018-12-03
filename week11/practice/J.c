#include <stdio.h>
#include <stdlib.h>
typedef int T;
int cmpInt(T a, T b) { return a < b; }
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

void quickSort(T *array, int (*compare)(T a, T b), int l, int r) {
    int i, j;
    T mid;
    if (r - l < 2) return;
    for (i = l, j = r - 1, mid = array[l]; i < j;) {
        while (compare(mid, array[j]) && i < j) j--;
        if (i < j) array[i++] = array[j];
        while (compare(array[i], mid) && i < j) i++;
        if (i < j) array[j--] = array[i];
    }
    array[i] = mid;
    quickSort(array, compare, l, i);
    quickSort(array, compare, i + 1, r);
}
int n, num[(int)1e6 + 5];
int i, gap;
int main() {
    scanf("%d", &n);
    if (n == 1 || n == 2) {
        printf("Yes");
        return 0;
    }
    for (i = 0; i < n; i++) scanf("%d", num + i);
    //quickSort(num, cmpInt, 0, n);
    qsort(num,n,sizeof(int),cmp);
    gap = num[1] - num[0];
    for (i = 2; i < n; i++)
        if (num[i] - num[i - 1] != gap) {
            printf("NO");
            return 0;
        }

    printf("Yes");
    return 0;
}
