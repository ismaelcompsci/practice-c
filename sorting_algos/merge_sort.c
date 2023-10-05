#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool _is_sorted(int *arr, int low, int high);
void merge(int *arr, int *aux, int lo, int mid, int hi);
void merge_sort(int *arr, int *aux, int lo, int hi);

void merge_sort(int *arr, int *aux, int lo, int hi) {

  // printf("lo: %i, hi: %i, ret: %s\n", lo, hi, hi<=lo ? "return" : "");
  if (hi <= lo)
    return;

  int mid = lo + (hi - lo) / 2;
  merge_sort(arr, aux, lo, mid);
  merge_sort(arr, aux, mid + 1, hi);
  if (arr[mid + 1] > arr[mid])
    return;
  merge(arr, aux, lo, mid, hi);
}

void merge(int *arr, int *aux, int lo, int mid, int hi) {
  assert(_is_sorted(arr, lo, mid) == true);     // precondition 1st half sorted.
  assert(_is_sorted(arr, mid + 1, hi) == true); // precondition 2nc half sorted.

  for (int k = lo; k <= hi; k++) {
    aux[k] = arr[k]; // copy to aux
  }

  int i = lo;
  int j = mid + 1;
  ;

  for (int k = lo; k <= hi; k++) {
    if (i > mid)
      arr[k] = aux[j++];
    else if (j > hi)
      arr[k] = aux[i++];
    else if (aux[j] < aux[i])
      arr[k] = aux[j++];
    else
      arr[k] = aux[i++];
  }

  assert(_is_sorted(arr, lo, hi) == true);
}

bool _is_sorted(int *arr, int low, int high) {

  for (int i = low; i < high; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }

  return true;
}


/* -------------------------yale---------------------- */

void _merge(int n1, const int a1[], int n2, const int a2[], int out[])
{
    int i1;
    int i2;
    int iout;

    i1 = i2 = iout = 0;

    while(i1 < n1 || i2 < n2) {
        if(i2 >= n2 || ((i1 < n1) && (a1[i1] < a2[i2]))) {
            /* a1[i1] exists and is smaller */
            out[iout++] = a1[i1++];
        }  else {
            /* a1[i1] doesn't exist, or is bigger than a2[i2] */
            out[iout++] = a2[i2++];
        }
    }
}

void mergeSort(int n, int a[], int out[]) {
  int *a1;
  int *a2;

  if (n < 2) {
    memcpy(out, a, sizeof(int) * n);
  } else {
    /* sort into temp arrays */
    a1 = malloc(sizeof(int) * (n/2));
    a2 = malloc(sizeof(int) * (n - (n / 2)));

    mergeSort(n/2, a, a1);
    mergeSort(n - n/2, a + n/2, a2);

    _merge(n/2,a1,  n - n / 2, a2, out);

    free(a1);
    free(a2);
  }
}
