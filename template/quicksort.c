typedef int T;
int cmpInt(T a, T b) { return a < b; }

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
