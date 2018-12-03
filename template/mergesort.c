#include <stdio.h>

typedef int T;
int cmpInt(T a, T b) { return a > b; }

// function 'compare' return 0 when they are sorted
// mergesort will sort array from array[l] to array[r-1]
void mergesort(T *array, T *buffer, int (*compare)(T a, T b), int l, int r) {
  int i, j, k;
  if (r - l < 2)
    return;
  mergesort(array, buffer, compare, l, (l + r) / 2);
  mergesort(array, buffer, compare, (l + r) / 2, r);
  for (i = l, j = (l + r) / 2, k = l; i < (l + r) / 2 && j < r; k++) {
    if (compare(array[i], array[j]))
      buffer[k] = array[j++];
    else
      buffer[k] = array[i++];
  }
  while (i < (l + r) / 2)
    buffer[k++] = array[i++];
  while (j < r)
    buffer[k++] = array[j++];
  for (i = l; i < r; i++)
    array[i] = buffer[i];
}
