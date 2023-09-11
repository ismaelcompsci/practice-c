#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_QUEUE
#define PROJECT_QUEUE

typedef struct Node
{
    void *data;
    struct Node *next;
} node;

typedef struct Queue
{
    node *head;
    node *tail;
    int data_size;

} queue_t;

queue_t *create_queue(int data_size);

/* enqueue: adds value at position at tail */
void enqueue(queue_t *q, void *data);

/* dequeue: returns value and removes least recently added element (front) */
void *dequeue(queue_t *q);

bool empty(queue_t *q);

void destroy_queue(queue_t *q);

#endif // PROJECT_QUEUE
