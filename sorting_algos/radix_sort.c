#include <string.h>

int get_max(int arr[], int len);
void counting_sort(int arr[], int len);
void radix_counting_sort(int arr[], int len, int exp);
void radix_sort(int arr[], int len);

int get_max(int arr[], int len) {

  int max = arr[0];

  for (int i = 0; i < len; i++)
    if (arr[i] > max)
      max = arr[i];

  return max;
}

void radix_sort(int arr[], int len) {
  int max = get_max(arr, len);

  for (int exp = 1; max / exp > 0; exp *= 10) {
    radix_counting_sort(arr, len, exp);
  }
}

void radix_counting_sort(int arr[], int len, int exp) {
  int output[len];
  int max = (arr[0] / exp) % 10;
  int i;

  for (i = 0; i < len; i++)
    if (arr[i] > max)
      max = arr[i];

  int count[max + 1];
  memset(count, 0, sizeof(int) * (max + 1));

  for (i = 0; i < len; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = len - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (i = 0; i < len; i++) {
    arr[i] = output[i];
  }
}

void counting_sort(int arr[], int len) {
  int i, max = get_max(arr, len); // Find out the maximum element
  int output[len];
  int count[max + 1]; // Initialize an array of length max+1 with all elements
                      // 0. This array is used for storing the count of the
                      // elements in the array.
  memset(count, 0, (max + 1) * sizeof(int));

  // Store the count of each element at their respective index in count array
  for (i = 0; i < len; i++) {
    count[arr[i]]++;
  }

  // Store cumulative sum of the elements of the count array.
  int total = 0;
  for (i = 0; i < len; i++) {
    int c = count[i];
    count[i] = total;
    total += c;
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (i = len - 1; i >= 0; --i) { // stable
    output[count[arr[i]] - 1] = arr[i];
    --count[arr[i]];
  }

  for (i = 0; i < len; i++) {
    arr[i] = count[i];
  }
}
