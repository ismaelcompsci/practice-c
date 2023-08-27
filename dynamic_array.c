#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dynamic_array.h"
#include "../log/log.h"
#include "../log/log.c"

int SUCCESS_MODE = 1;
int INFO_MODE = 0;
int ERROR_MODE = 0;
int DEBUG_MODE = 0;

int main(void)
{
    run_all_tests();
    return 0;
}

/* new_array: return new DArray with specified capacity */
DArray *new_array(int capacity)
{

    logger(INFO, "creating array...\n");
    int cap = create_capacity(capacity);
    DArray *arr = malloc(sizeof(DArray));

    arr->capacity = cap;
    arr->len = 0;
    arr->data = (int *)malloc(sizeof(int) * cap);

    validate_memory(arr->data);

    return arr;
}

/* at: returns item at given index, blows up if index out of bounds */
int at(DArray *arr, int index)
{
    if (index > arr->capacity || index > arr->len)
    {
        logger(ERROR, "index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return *(arr->data + index);
}

/* delete_ - delete_ item at index, shifting all trailing elements left */
void delete_(DArray *arr, int index)
{
    if (index < 0)
        exit(EXIT_FAILURE);

    *(arr->data + index) = 0;

    memmove(arr->data + index, arr->data + index + 1, (arr->len - index) * sizeof(int));

    arr->len--;
    resize(arr, arr->len);
}
/* remove - looks for value and removes index holding it (even if in multiple places)*/
void remove_item(DArray *arr, int item)
{
    int index;
    while ((index = find(arr, item)) != -1)
        delete_(arr, index);
}

/*  insert: inserts item at index, shifts that index's value and trailing elements to the right */
void insert(DArray *arr, int index, int item)
{

    if (index < 0 || index > arr->len - 1)
    {
        logger(ERROR, "index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    resize(arr, arr->len + 1);

    /* one way  */
    // for (int i = arr->len; i >= index; i--)
    //     *(arr->data + i + 1) = *(arr->data + i);

    /* other way */
    memmove(arr->data + index + 1, arr->data + index, (arr->len - index) * sizeof(int));

    *(arr->data + index) = item;
    arr->len++;
}

/* pop:  remove from end, return value */
int pop(DArray *arr)
{
    if (arr->len == 0)
        exit(EXIT_FAILURE);
    resize(arr, arr->len - 1);

    int item = *(arr->data + arr->len - 1);
    arr->len--;

    return item;
}

/* prepend: can use insert above at index 0 */
void prepend(DArray *arr, int item)
{

    insert(arr, 0, item);
}

/* find: looks for value and returns first index with that value, -1 if not found*/
int find(DArray *arr, int item)
{
    for (int i = 0; i < arr->len; i++)
        if (*(arr->data + i) == item)
            return i;

    return -1;
}

void push(DArray *arr, int item)
{

    logger(INFO, "pushing to array\n");

    resize(arr, arr->len + 1);
    *(arr->data + arr->len) = item;
    arr->len++;
}

/* size: returns size of DArray aka length of array */
int size(DArray *arr) { return arr->len; }

/* capacity: returns capacity of DArray */
int capacity(DArray *arr) { return arr->capacity; }

/* is_empty: returns 1 if empty otherwise 0*/
int is_empty(DArray *arr) { return (arr->len == 0); }

/* resize: either increases or decreses memory size */
void resize(DArray *arr, int length)
{

    logger(INFO, "resizing array...\n");

    if (length >= arr->capacity)
        // grow array
        grow_array(arr);

    else if (length < arr->capacity / SHRINKFACTOR)
        // shrink array
        shrink_array(arr);
    else
        // else do nothing
        logger(INFO, "no resize required\n");
}

/* create_capacity: returns a valid capacity with a minimum of 16 */
int create_capacity(int cap)
{
    int valid_capacity = MINCAPACITY;

    if (cap < 1)
    {
        logger(ERROR, "invalid capacity\n");
        exit(EXIT_FAILURE);
    }

    while (cap > valid_capacity / GROWTHFACTOR)
        valid_capacity *= GROWTHFACTOR;

    return valid_capacity;
}

/* grow_array: grows array capacity determined by current capacity */
void grow_array(DArray *arr)
{

    logger(INFO, "growing array\n");

    int cap = create_capacity(arr->capacity);

    logger(INFO, "new capacity %i->%i\n", arr->capacity, cap);

    arr->capacity = cap;
    arr->data = (int *)realloc(arr->data, sizeof(int) * cap);

    validate_memory(arr->data);
}

/* shrink_array: shrinks current capacity by 4*/
void shrink_array(DArray *arr)
{

    logger(INFO, "shrinking array\n");

    int cap = arr->capacity / SHRINKFACTOR;
    cap < MINCAPACITY ? cap = MINCAPACITY : cap; // mininum of 16

    logger(INFO, "new capacity %i->%i\n", arr->capacity, cap);

    arr->capacity = cap;
    arr->data = (int *)realloc(arr->data, sizeof(int) * cap);
}

/* validate_memory: checks if pointer points to NULL */
void validate_memory(void *p)
{

    logger(INFO, "validating memory allocation...\n");

    if (p == NULL)
    {
        logger(ERROR, "Falied to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

/* destroy: frees all memory DArray uses */
void destroy(DArray *arr)
{
    logger(DEBUG, "Destrying array\n");
    free(arr->data);
    free(arr);
}

/*
 * TESTS
 */

void run_all_tests()
{
    test_new_array();
    test_push();
    test_resize();
    test_is_empty();
    test_at();
    test_insert();
    test_prepend();
    test_pop();
    test_delete_();
    test_remove_item();
    test_find_exists();
    test_find_not_exists();
}

void test_new_array()
{
    DArray *arr = new_array(5);
    int init_size = size(arr);

    assert(init_size == 0);
    destroy(arr);
    logger(SUCCESS, "new_array passed\n");
}

void test_push()
{
    DArray *arr = new_array(2);
    push(arr, 2);
    push(arr, 4);

    int arr_size = size(arr);

    assert(arr_size == 2);
    destroy(arr);
    logger(SUCCESS, "size passed\n");
}

void test_resize()
{
    DArray *arr = new_array(2);

    int old_capacity = capacity(arr);
    assert(old_capacity == 16);

    // forces a resize up
    for (int i = 0; i < 18; ++i)
        push(arr, i + 1);

    assert(capacity(arr) == 32);

    // forces a resize down
    for (int j = 0; j < 15; ++j)
        pop(arr);

    assert(capacity(arr) == 16);

    destroy(arr);

    logger(SUCCESS, "resize passed\n");
}

void test_is_empty()
{
    DArray *arr = new_array(2);

    int empty = is_empty(arr);
    assert(empty == 1);

    push(arr, 1);
    empty = is_empty(arr);
    assert(empty == 0);

    destroy(arr);
    logger(SUCCESS, "is_empty passed\n");
}

void test_at()
{
    DArray *arr = new_array(12);
    for (int i = 0; i < 12; ++i)
    {
        push(arr, i + 3);
    }
    assert(at(arr, 6) == 9);

    destroy(arr);
    logger(SUCCESS, "at passed\n");
}

void test_insert()
{
    DArray *arr = new_array(5);
    for (int i = 0; i < 5; ++i)
        push(arr, i + 5);

    insert(arr, 2, 47);
    assert(size(arr) == 6);
    assert(at(arr, 2) == 47);
    assert(at(arr, 3) == 7);

    destroy(arr);

    logger(SUCCESS, "insert passed\n");
}

void test_prepend()
{
    DArray *arr = new_array(5);
    for (int i = 0; i < 5; ++i)
        push(arr, i + 5);

    prepend(arr, 89);
    assert(at(arr, 0) == 89);

    destroy(arr);
    logger(SUCCESS, "prepend passed\n");
};

void test_pop()
{
    DArray *arr = new_array(5);
    for (int i = 0; i < 3; ++i)
        push(arr, i + 1);

    assert(arr->len == 3);

    for (int j = 0; j < 3; ++j)
    {

        int v = pop(arr);
        assert(v == 3 - j); // 3 2 1
    }

    assert(is_empty(arr) == 1);
    destroy(arr);

    logger(SUCCESS, "pop passed\n");
}

void test_delete_()
{
    DArray *arr = new_array(5);

    push(arr, 12);
    push(arr, 3);
    push(arr, 41);
    push(arr, 12);
    push(arr, 12);

    assert(at(arr, 2) == 41);
    delete_(arr, 2);
    assert(at(arr, 2) == 12);

    assert(size(arr) == 4);
    destroy(arr);

    logger(SUCCESS, "delete_ passed\n");
}

void test_remove_item()
{
    DArray *arr = new_array(5);

    push(arr, 12);
    push(arr, 3);
    push(arr, 41);
    push(arr, 12);
    push(arr, 12);

    remove_item(arr, 12);

    assert(size(arr) == 2);
    destroy(arr);

    logger(SUCCESS, "remove_item passed\n");
}

void test_find_exists()
{
    DArray *arr = new_array(5);
    push(arr, 1);
    push(arr, 2);
    push(arr, 3);
    push(arr, 4);
    push(arr, 5);
    assert(find(arr, 1) == 0);
    assert(find(arr, 4) == 3);
    assert(find(arr, 5) == 4);
    destroy(arr);

    logger(SUCCESS, "find exists passed\n");
}

void test_find_not_exists()
{
    DArray *arr = new_array(3);
    push(arr, 1);
    push(arr, 2);
    push(arr, 3);
    assert(find(arr, 7) == -1);
    destroy(arr);
    logger(SUCCESS, "find not exists passed\n");
}