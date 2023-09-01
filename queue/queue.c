#include "queue.h"
#include "../log/log.h"
#include "../log/log.c"

int SUCCESS_MODE = 1;
int INFO_MODE = 1;
int ERROR_MODE = 0;
int DEBUG_MODE = 0;

queue_t *create_queue()
{
    queue_t *q = malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enqueue(queue_t *q, int data)
{
    logger(INFO, "enqueing %i\n", data);
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        logger(ERROR, "enqueue NULL pointer", data);
        exit(EXIT_FAILURE);
    }
    new->data = data;
    new->next = NULL;

    if (q->tail)
        q->tail->next = new;

    q->tail = new;

    if (q->head == 0)
        q->head = new;
    logger(INFO, "enqueued %i\n", data);
}

int dequeue(queue_t *q)
{
    if (empty(q))
    {
        logger(ERROR, "list is emtpy\n");
        exit(EXIT_FAILURE);
    }
    logger(INFO, "dequeing...\n");
    int val;

    if (q->head->next)
    {
        logger(INFO, "moving head\n");
        val = q->head->data;
        q->head = q->head->next;
    }
    else
    {
        logger(INFO, "head is only value\n");
        val = q->head->data;
        q->head = NULL;
        q->tail = NULL;
    }

    logger(INFO, "dequeued %i\n", val);
    return val;
}

bool empty(queue_t *q)
{
    if (q->head == NULL && q->tail == NULL)
        return true;

    return false;
}

void destroy_queue(queue_t *q)
{
    queue_t *curr = q->head;
    queue_t *temp = q->head;

    while (curr)
    {
        temp = curr;
        curr = curr->head->next;
        free(temp);
    }

    free(q);
}