#include "../log/log.h"
#include "../log/log.c"

int SUCCESS_MODE = 1;
int INFO_MODE = 1;
int ERROR_MODE = 0;
int DEBUG_MODE = 0;

hash_table *create_table(int size)
{
    logger(INFO, "Creating hash table of size %i\n", size);
    hash_table *table = malloc(sizeof(hash_table));
    check_address(table);

    table->data = malloc(sizeof(key_value) * size); // creating array
    check_address(table->data);

    // init null
    for (int i = 0; i < size; i++)
    {
        table->data[i] = NULL;
    }

    table->size = size;

    logger(INFO, "Finished creating hash table\n", size);
    return table;
}

void add(hash_table *table, char *key, char *value)
{

    key_value *kv = get(table, key);

    if (kv != NULL)
    {
        free(kv->value);
        kv->value = strdup(value);
    }
    else
    {
        int index = hash(key, table->size);
        key_value *new = malloc(sizeof(key_value));

        new->key = strdup(key);
        new->value = strdup(value);

        new->next = table->data[index];
        table->data[index] = new;
    }
}

bool exists(hash_table *table, char *key)
{
    key_value *found = get(table, key);

    return found != NULL;
}

key_value *get(hash_table *table, char *key)
{
    logger(INFO, "Searching for value with key: %s\n", key);
    int index = hash(key, table->size);
    logger(INFO, "Hash for key is %i\n", index);

    key_value *node = table->data[index]; // head of list

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return node; 

        node = node->next;
    }

    return NULL;
}

void remove_(hash_table *table, char *key)
{
    int index = hash(key, table->size);

    key_value *item = table->data[index];
    key_value *prev = NULL;

    while (item)
    {
        logger(INFO, "item->key = %s, item->value = %s\n", item->key, item->value);
        if (strcmp(table->data[index]->key, key) == 0)
        {
            logger(INFO, "remove: %s , item->key = %s, item->value = %s\n", table->data[index]->key, item->key, item->value);
            if (prev == NULL)
            {
                logger(INFO, "HEAD\n");
                // if head
                table->data[index] = item->next;
            }
            else
            {
                logger(INFO, "OTHER\n");
                // if middle of list;
                prev->next = item->next;
            }

            free(item->key);
            free(item->value);
            free(item);
        }

        prev = item;
        item = item->next;
    }
}

int hash(const char *key, const int m)
{
    int hash = 0;

    for (int i = 0; i < key[i] != '\0'; ++i)
    {
        hash = hash * 31 + key[i];
    }

    return abs(hash % m);
}

void check_address(void *p)
{
    if (p == NULL)
    {
        logger(ERROR, "Pointer points to NULL");
        exit(EXIT_FAILURE);
    }
}