#include "../log/log.h"
#include "../log/log.c"

#include "linked_list.h"

int SUCCESS_MODE = 1;
int INFO_MODE = 0;
int ERROR_MODE = 0;
int DEBUG_MODE = 0;

void print_list(node_t *head)
{
    node_t *current = head;

    while (current)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("\n");
}

void check_address(void *ptr)
{

    if (ptr == NULL)
    {
        logger(ERROR, "pointer is null\n");
        exit(EXIT_FAILURE);
    }
}

void destroy_linked_list(node_t *head)
{
    node_t *current = head;

    while (current)
    {
        node_t *next = current->next;
        free(current);
        current = next;
    }

    logger(INFO, "freed linked list\n");
}

int size(node_t *head)
{
    int i;

    node_t *curr = head;
    i = 0;
    logger(INFO, "getting size\n");
    while (curr)
    {
        curr = curr->next;
        i++;
    }
    return i;
}

void push_front(node_t **head, int data)
{
    logger(INFO, "pushing %i to the front\n", data);

    node_t *new = malloc(sizeof(node_t));
    check_address(new);

    new->data = data;
    new->next = *head;

    *head = new;
}

int pop_front(node_t **head)
{
    logger(INFO, "popping from the front\n");
    empty_check(head);

    int data = (*head)->data;

    // *head = (*head)->next;
    node_t *first = *head;

    *head = first->next;
    free(first);

    return data;
}

bool empty(node_t *head)
{
    logger(INFO, "checking if emtpy\n");
    if (head == NULL)
    {
        logger(INFO, "list is emtpy\n");
        return true;
    }

    return false;
}

void push_back(node_t **head, int data)
{
    logger(INFO, "pushing %i to the end\n", data);
    node_t *new = malloc(sizeof(node_t));

    new->data = data;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return;
    }

    node_t *curr = *head;
    while (curr->next)
        curr = curr->next;

    curr->next = new;
}

int pop_back(node_t **head)
{
    if (empty(*head))
        exit(EXIT_FAILURE);

    node_t *curr = *head;
    node_t *prev = NULL;

    while ((curr->next) != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    int data = curr->data;

    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    free(curr);

    return data;
}

int front(node_t *head)
{
    empty_check(head);

    return head->data;
}

int back(node_t *head)
{
    empty_check(head);

    node_t *curr = head;

    while (curr->next)
        curr = curr->next;

    return curr->data;
}

int value_at(node_t *head, int index)
{
    logger(INFO, "getting value at index: %i\n", index);
    node_t *curr = head;
    while (index > 0 && curr != NULL)
    {
        curr = curr->next;
        index--;
    }

    return curr->data;
}

void insert(node_t **head, int index, int data)
{
    int i;
    node_t *curr = *head;
    node_t *prev = NULL;

    for (i = 0; i < index && curr; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    if (i != index)
    {
        logger(ERROR, "Index out of bounds");
        exit(EXIT_FAILURE);
    }

    node_t *new = malloc(sizeof(node_t));
    new->data = data;
    new->next = NULL;

    if (prev)
    {
        new->next = curr;
        prev->next = new;
    }
    else
    {
        new->next = *head;
        *head = new;
    }
}

void erase(node_t **head, int index)
{
    int i;
    node_t *curr = *head;
    node_t *prev = NULL;

    for (i = 0; i < index && curr; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    if (i != index)
    {
        logger(ERROR, "Index out of bounds");
        exit(EXIT_FAILURE);
    }

    if (prev)
    {
        prev->next = curr->next;
        *head = prev;
    }
    else
        *head = curr->next;

    free(curr);
}

int value_n_from_end(node_t *head, int n)
{
    int len = size(head);

    if (n > len)
    {
        logger(ERROR, "index out of bounds");
        exit(EXIT_FAILURE);
    }

    int pos = len - n;

    node_t *curr = head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    return curr->data;
}

void reverse(node_t **head)
{
    node_t *curr = *head;
    node_t *next = *head;
    node_t *prev = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    *head = prev;
}

void remove_value(node_t **head, int value)
{
    node_t *curr = *head;
    node_t *prev = NULL;

    while (curr)
    {

        if (curr->data == value)
        {
            if (prev)
                prev->next = curr->next;
            else
                *head = curr->next;

            free(curr);
        }
        prev = curr;
        curr = curr->next;
    }
}

void empty_check(node_t *head)
{
    if (empty(head))
        exit(EXIT_FAILURE);
}