#ifndef ARRAY_H
#define ARRAY_H

int MINCAPACITY = 16;
int GROWTHFACTOR = 2;
int SHRINKFACTOR = 4;

typedef struct DynamicArray
{
    int len;
    int capacity;
    int *data;
} DArray;

void resize(DArray *, int);
void insert(DArray *, int, int);
void prepend(DArray *, int);
void push(DArray *, int);
int find(DArray *, int);
DArray *new_array(int);
int at(DArray *, int);
void shrink_array(DArray *);
void validate_memory(void *);
void grow_array(DArray *);
int create_capacity(int);
int is_empty(DArray *);
int capacity(DArray *);
int size(DArray *);
int pop(DArray *);
void remove_item(DArray *, int);

void run_all_tests();
void logger(int, char *, ...);
void info(char *);

/* TESTS */
void test_new_array();
void test_push();
void test_resize();
void test_is_empty();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_delete_();
void test_remove_item();
void test_find_not_exists();
void test_find_exists();

#endif