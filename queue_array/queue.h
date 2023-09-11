#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_QUEUE
#define PROJECT_QUEUE

const int QUEUE_CAP = 5;
const int QUEUE_POSITIONS = QUEUE_CAP + 1;

typedef struct Queue
{
    int arr[QUEUE_POSITIONS];
    int read;
    int write;
    int cap;

} queue_t;

queue_t *create_queue();

/* enqueue: adds value at position at tail */
void enqueue(queue_t *q, int data);

/* dequeue: returns value and removes least recently added element (front) */
int dequeue(queue_t *q);

bool empty(queue_t *q);
bool full(queue_t *q);
void destroy_queue(queue_t *q);

#endif // PROJECT_QUEUE
