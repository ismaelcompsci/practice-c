#include "queue.h"
#include "../log/log.h"
#include "../log/log.c"

int SUCCESS_MODE = 1;
int INFO_MODE = 1;
int ERROR_MODE = 1;
int DEBUG_MODE = 0;

queue_t *create_queue()
{
    queue_t *q = malloc(sizeof(queue_t));

    q->read = 0;
    q->write = 0;
    q->cap = QUEUE_CAP;
    logger(INFO, "created queue of size: %lu\n", (unsigned long)sizeof(queue_t));

    return q;
}

bool full(queue_t *q)
{
    return q->read == (q->write + 1) % QUEUE_POSITIONS;
}

void enqueue(queue_t *q, int data)
{
    if (full(q))
    {
        logger(ERROR, "LIST IS FULL\n");
        exit(EXIT_FAILURE);
    }

    logger(INFO, "EN: %i, at pos: %i\n", data, q->write);
    q->arr[q->write] = data;
    q->write = (q->write + 1) % QUEUE_POSITIONS;
}

int dequeue(queue_t *q)
{
    if (empty(q))
    {
        logger(ERROR, "queue is empty");
        exit(EXIT_FAILURE);
    }

    int val = q->arr[q->read];
    q->arr[q->read] = 0;

    q->read = (q->read + 1) % QUEUE_POSITIONS;

    return val;
}

bool empty(queue_t *q)
{
    if (q->read == q->write)
        return true;
    return false;
}

void destroy_queue(queue_t *q)
{
    free(q);
}