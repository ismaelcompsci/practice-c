#include "heap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(max_heap *heap, int value) {
  if (heap->size == heap->capacity) {
    printf("can't insert more items.");
    exit(EXIT_FAILURE);
  }

  heap->size++;

  heap->elements[heap->size] = value;

  sift_up(heap, heap->size);
}

void sift_up(max_heap *heap, int size) {
  int parent;
  int tmp;

  while (size > 1) {
    parent = size / 2;

    if (heap->elements[size] > heap->elements[parent]) {
      tmp = heap->elements[parent];
      heap->elements[parent] = heap->elements[size];
      heap->elements[size] = tmp;
    }
    size = parent;
  }
}

int get_size(max_heap *heap) { return heap->size; }

int get_max(max_heap *heap) {
  /* max-heap root node is max */
  return heap->elements[1];
}

/* returns true if heap contains no elements */
bool is_empty(max_heap *heap) { return heap->size == 0 ? true : false; }

int extract_max(max_heap *heap) {

  int value = get_max(heap);
  /* fix heap */

  /* fill hole with last entry */
  heap->elements[1] = heap->elements[heap->size]; // last entry;
  heap->size--;                                   // accounting
  sift_down(heap, 1);

  return value;
}

void sift_down(max_heap *heap, int index) {
  /* bubble root down heap */

  if (is_empty(heap))
    return;

  int tmp;
  int swap_index;
  int i = index;

  while (i * 2 <= heap->size) {
    int left = i * 2;
    int right = i * 2 + 1;

    bool left_child_exits = left <= heap->size;
    bool right_child_exits = right <= heap->size;

    /* swap x with greatest child */
    if (left_child_exits && right_child_exits) {
      if (heap->elements[left] > heap->elements[right])
        swap_index = left;
      else
        swap_index = right;
    } else if (left_child_exits)
      swap_index = left;
    else if (right_child_exits)
      swap_index = right;
    else
      break;

    if (heap->elements[swap_index] > heap->elements[i]) {
      tmp = heap->elements[i];
      heap->elements[i] = heap->elements[swap_index];
      heap->elements[swap_index] = tmp;

      i = swap_index;
    } else
      break;
  }
}

void remove_node(max_heap *heap, int index) {
  heap->elements[index] = heap->elements[heap->size];
  heap->size--;
  sift_down(heap, index);
}

void heapify(int *arr, int length) {
  for (int i = length / 2; i > 0; i--)
    max_heapify(arr, length, i);
}

void max_heapify(int *arr, int heap_size, int index) {
  int left = 2 * index;
  int right = 2 * index + 1;

  int largest = index;

  if (left < heap_size && arr[left] > arr[index])
    largest = left;

  if (right < heap_size && arr[right] > arr[largest])
    largest = right;

  if (largest != index) {
    int tmp;
    tmp = arr[largest];
    arr[largest] = arr[index];
    arr[index] = tmp;
    max_heapify(arr, heap_size, largest);
  }
}

/**
 * Turn array into a heap.
 * Heap heap
 * 1 index array
 */

void heap_sort(int *arr, int size) {
  int tmp;
  heapify(arr, size);

  for (int i = size - 1; i > 0; i--) {
    tmp = arr[0];
    arr[0] = arr[i];
    arr[i] = tmp;

    max_heapify(arr, i, 0);
  }
}

/* ------------------------------- helpers
 * --------------------------------------*/

void print_data(int *arr, int size) {
  for (int i = 1; i <= size; ++i) {
    printf("%4d |", arr[i]);
  }
  putchar('\n');
}
