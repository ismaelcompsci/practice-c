#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifndef PROJECT_HASH_TABLE
#define PROJECT_HASH_TABLE

const int TABLE_SIZE = 100;
char *DUMMY = "<trash>";

typedef struct KeyValuePair
{
    char *key;
    char *value;
    struct KeyValuePair *next;
} key_value;

typedef struct HashTable
{
    key_value **data;
    int size;
} hash_table;

hash_table *create_table(int size);
void check_address(void *p);

// - hash(k, m) - m is size of hash table
int hash(const char *key, const int m);

// - add(key, value) - if key already exists, update value
void add(hash_table *table, char *key, char *value);

// - exists(key)
bool exists(hash_table *table, char *key);

// - get(key)
key_value *get(hash_table *table, char *key);

// - remove(key)
void remove_(hash_table *table, char *key);

#endif