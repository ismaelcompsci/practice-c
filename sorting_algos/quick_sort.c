#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int lo, int hi) {
  int i = lo;
  int j = hi + 1;

  int tmp;

  // lo is pivot

  while (true) {
    while (a[++i] < a[lo]) 
      if (i == hi)
        break;

    while (a[lo] < a[--j])
      if (j == lo)
        break;

    if (i >= j)
      break;

    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

  tmp = a[lo];
  a[lo] = a[j];
  a[j] = tmp;

  return j;
}

void quick_sort(int *arr, int lo, int hi) {
  if (hi <= lo)
    return;

  int j = partition(arr, lo, hi);
  quick_sort(arr, lo, j - 1);
  quick_sort(arr, j + 1, hi);
}

void random_shuffle(int *arr, size_t n) {


  if (n > 1) {
    size_t i;

    for (i = 0; i < n; i++) {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = arr[j];
      arr[j] = arr[i];
      arr[i] = t;
    }
  }

}
