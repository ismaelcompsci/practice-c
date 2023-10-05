#include <stdio.h>

#ifndef PROJECT_HEAP
#define PROJECT_HEAP

const int CAPACITY = 1000;

typedef struct MaxHeap
{
    int size;
    int elements[CAPACITY + 1];
    int capacity;
} max_heap;

void insert(max_heap *heap, int value);
void sift_up(max_heap *heap, int size);
void sift_down(max_heap *heap, int index);
int get_max(max_heap *heap);
void remove_node(max_heap *heap, int index);

void heapify(int *arr, int len);
void max_heapify(int *arr, int heap_size, int index);
void print_data(int *arr, int size);
#endif
