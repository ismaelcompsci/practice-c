#include "./bubble_sort.c"
#include "./insertion_sort.c"
#include "./merge_sort.c"
#include "./quick_sort.c"
#include "./radix_sort.c"
#include "./selection_sort.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 20

void random_array(int *arr, int len);
bool is_sorted(int *arr, int len);
void print_array(int *arr, int len);

int main(void) {
  int qs[ARR_SIZE];
  int ms[ARR_SIZE];
  int aux[ARR_SIZE];
  int is[ARR_SIZE];
  int ss[ARR_SIZE];
  int rs[ARR_SIZE];
  int bs[ARR_SIZE];

  random_array(bs, ARR_SIZE);
  random_array(rs, ARR_SIZE);
  random_array(ss, ARR_SIZE);
  random_array(is, ARR_SIZE);
  random_array(qs, ARR_SIZE);
  random_array(ms, ARR_SIZE);

  radix_sort(rs, ARR_SIZE);
  quick_sort(qs, 0, ARR_SIZE);
  merge_sort(ms, aux, 0, ARR_SIZE - 1);
  insertion_sort(is, ARR_SIZE);
  selection_sort(ss, ARR_SIZE);
  bubble_sort(bs, ARR_SIZE);


  printf("quick_sort  %s\n", is_sorted(qs, ARR_SIZE) ? "true" : "false");
  printf("merge_sort  %s\n", is_sorted(ms, ARR_SIZE) ? "true" : "false");
  printf("insertion_sort  %s\n", is_sorted(is, ARR_SIZE) ? "true" : "false");
  printf("selection_sort  %s\n", is_sorted(ss, ARR_SIZE) ? "true" : "false");
  printf("radix_sort  %s\n", is_sorted(rs, ARR_SIZE) ? "true" : "false");
  printf("bubble_sort  %s\n", is_sorted(bs, ARR_SIZE) ? "true" : "false");

  exit(EXIT_SUCCESS);
}

void random_array(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % 1000 + 1;
  }
}

bool is_sorted(int *arr, int len) {
  for (int i = 1; i < len; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

void print_array(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf(" |%i| ", arr[i]);
  }
  printf("\n");
}
