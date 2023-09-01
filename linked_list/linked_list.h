#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_LINKED_LIST
#define PROJECT_LINKED_LIST

typedef struct Node
{
    int data;
    struct Node *next;
    
} node_t;

/* size: returns number of data elements in list */
int size(node_t *head);

/* push_front: adds an item to the front of the list */
void push_front(node_t **head, int data);

/* pop_front remove front item and return its value */
int pop_front(node_t **head);

/* push_back: adds an item at the end */
void push_back(node_t **head, int data);

/* pop_back: removes end item and returns its value */
int pop_back(node_t **head);

/* front: get value of front item */
int front(node_t *head);

/* back: get value of end item */
int back(node_t *head);

/**
 *  insert(index, value) - insert value at index, so current item at that index
 *  is pointed to by new item at index
 * */
void insert(node_t **head, int index, int data);

/* erase: removes node at given index */
void erase(node_t **head, int index);

/*  value_n_from_end(n) - returns the value of the node at
    nth position from the end of the list
*/
int value_n_from_end(node_t *head, int n);

/* reverse: reverses the list */
void reverse(node_t **head);

/* remove_value: removes the first item in the list with this value */
void remove_value(node_t **head, int value);

/* value_at: returns the value of the nth item (starting at 0 for first) */
int value_at(node_t *head, int index);

/* empty: bool returns true if empty */
bool empty(node_t *head);

/* destroy_linked_list: frees memeory used by list */
void destroy_linked_list(node_t *head);

void print_list(node_t *head);

void empty_check(node_t *head);

#endif
