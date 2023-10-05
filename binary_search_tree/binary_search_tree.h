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
int get_node_count(bst_node *root);

bst_node *get_successor(bst_node *root, int data);

int get_height(bst_node *root);

bst_node *delete_value(bst_node *root, int value);
bst_node *get_min(bst_node *root);
int get_max(bst_node *root);

void insert(bst_node **root, int);
bst_node *r_insert(bst_node *root, int);
void delete_tree(bst_node *root);

bool search(bst_node **root, int);
bst_node *r_search(bst_node *root, int value);
bool is_binary_search_tree(bst_node *root);
bool is_subtree_lesser(bst_node *root, int value);
bool is_subtree_greater(bst_node *root, int value);

bool is_bst(bst_node *root);
bool is_bst_util(bst_node *root, int minValue, int maxValue);

void pre_order(bst_node *root);
void post_order(bst_node *root);
void in_order(bst_node *root);

void traverse(bst_node *root);

#endif