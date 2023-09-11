#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef PROJECT_BINARY_SEARCH_TREE
#define PROJECT_BINARY_SEARCH_TREE

typedef struct BstNode
{
    int number;
    struct BstNode *left;
    struct BstNode *right;

} bst_node;

int max(int a, int b);

bst_node *create_tree(int);
bool is_in_tree(bst_node *root, int value);

void print_values(bst_node *root, int space);
void level_order(bst_node *root);

int get_height(bst_node *root);

int get_min(bst_node *root);
int get_max(bst_node *root);

void insert(bst_node **root, int);
bst_node *r_insert(bst_node *root, int);

bool search(bst_node **root, int);
bool r_search(bst_node *root, int);

#endif