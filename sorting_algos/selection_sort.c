#include <stdio.h>

void selection_sort(int arr[], int n) {

  int tmp, i, j, min_idx;

  for (i = 0; i < n - 1; i++) {

    min_idx = i;
    for (j = i + 1; j < n; j++) {

      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    if (min_idx != i) {
      tmp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = tmp;
    }
  }
}
