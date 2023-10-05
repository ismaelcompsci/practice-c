#include "../log/log.h"
#include "heap.c"
#include "heap.h"

int SUCCESS_MODE = 1;
int INFO_MODE = 1;
int ERROR_MODE = 0;
int DEBUG_MODE = 0;

int main(void) {
  max_heap p_q;
  p_q.size = 0;
  p_q.capacity = CAPACITY;

  insert(&p_q, 4);
  assert(get_size(&p_q) == 1);
  insert(&p_q, 14);
  assert(get_size(&p_q) == 2);
  insert(&p_q, 34);
  assert(get_size(&p_q) == 3);
  insert(&p_q, 15);
  insert(&p_q, 5);
  insert(&p_q, 12);
  insert(&p_q, 46);
  insert(&p_q, 19);
  insert(&p_q, 17);
  insert(&p_q, 11);
  insert(&p_q, 17);
  assert(get_size(&p_q) == 11);

  assert(get_max(&p_q) == 46);

  remove_node(&p_q, 2);

  assert(get_size(&p_q) == 10);

  assert(extract_max(&p_q) == 46);
  assert(get_size(&p_q) == 9);
  assert(extract_max(&p_q) == 34);
  assert(get_size(&p_q) == 8);
  assert(extract_max(&p_q) == 17);
  assert(extract_max(&p_q) == 17);
  assert(extract_max(&p_q) == 15);
  assert(extract_max(&p_q) == 14);
  assert(extract_max(&p_q) == 12);
  assert(extract_max(&p_q) == 11);
  assert(extract_max(&p_q) == 5);
  assert(get_size(&p_q) == 1);
  assert(extract_max(&p_q) == 4);
  assert(get_size(&p_q) == 0);

  assert(is_empty(&p_q));

  int to_sort[11] = {0, 10, 123, 43, 17, 13, 9, 422, 2477, 18, 53};
  int sorted[11] = {0, 9, 10, 13, 17, 18, 43, 53, 123, 422, 2477};

  // will do this one with a 1 indexed array, sorted in place

  heap_sort(to_sort, 11);

  for (int i = 0; i < 10; ++i) {
    printf("%5d ", to_sort[i]);
  }

  // compares 2 arrays for exact match
  assert(memcmp(to_sort, sorted, sizeof(to_sort)) == 0);

  logger(SUCCESS, "ALL FUNCTIONS PASSED\n");
  exit(0);
}
