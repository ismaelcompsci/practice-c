

void bubble_sort(int arr[], int len);

void bubble_sort(int arr[], int len) {

  for (int i = 0; i < len - 1; i++) {

    int swapped = 0;

    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;

        swapped = 1;
      }
    }
          // list is sorted
      if (swapped == 0)
        break;
  }
}
