

void insertion_sort(int *arr, int len) {
  int tmp;

  for (int i = 1; i < len; i++) {
    int value = arr[i];
    int hole = i;

    while (hole > 0 && arr[hole - 1] > value) {
      int tmp = arr[hole];
      arr[hole] = arr[hole - 1];
      arr[hole - 1] = tmp;
      hole--;
    }
  }
}
