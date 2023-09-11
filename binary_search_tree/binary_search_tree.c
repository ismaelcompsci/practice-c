#include "../log/log.h"
#include "binary_search_tree.h"
#include <math.h>
#include "../queue/queue.h"
#include "../queue/queue.c"

bst_node *create_tree(int value)
{

    bst_node *root = (bst_node *)malloc(sizeof(bst_node));

    root->number = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

bst_node *r_insert(bst_node *root, int value)
{
    if (root == NULL)
        root = create_tree(value);
    else if (value <= root->number)
        root->left = r_insert(root->left, value);
    else
        root->right = r_insert(root->right, value);

    return root;
}

int get_height(bst_node *root)
{
    if (root == NULL)
        return -1;
    return 1 + max(get_height(root->left), get_height(root->right));
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int get_min(bst_node *root)
{

    if (root == NULL)
    {
        logger(ERROR_MODE, "TREE IS EMPTY\n");
        exit(EXIT_FAILURE);
    }
    bst_node *current = root;
    while (current->left)
    {
        current = current->left;
    }

    return current->number;
}

int get_max(bst_node *root)
{
    /**
     * if (root == NULL) {
     *      Error
     * } else if  (root->right == NULL) {
     *      return root->number;
     * }
     * return get_max(root->right);
     */
    if (root == NULL)
    {
        logger(ERROR_MODE, "TREE IS EMPTY\n");
        exit(EXIT_FAILURE);
    }
    bst_node *current = root;
    while (current->right)
    {
        current = current->right;
    }

    return current->number;
}

bool is_in_tree(bst_node *root, int value)
{
    return r_search(root, value);
}

void insert(bst_node **root, int value)
{
    if (*root == NULL)
        *root = create_tree(value);
    else
    {
        bst_node *currentNode = *root;

        while (currentNode)
        {
            if (currentNode->number < value)
            {
                if (currentNode->right == NULL)
                {
                    currentNode->right = create_tree(value);
                    break;
                }
                else
                    currentNode = currentNode->right;
            }
            else
            {
                if (currentNode->left == NULL)
                {
                    currentNode->left = create_tree(value);
                    break;
                }
                else
                    currentNode = currentNode->left;
            }
        }
    }
}

bool r_search(bst_node *root, int value)
{
    if (root == NULL)
        return false;
    else if (root->number == value)
        return true;
    // return root;
    else if (value <= root->number)
        return r_search(root->left, value);
    else
        return r_search(root->right, value);
}

const int SPACE = 8;
void print_values(bst_node *root, int space)
{
    if (root == NULL)
        return;

    space += SPACE;

    print_values(root->right, space);
    printf("\n");
    for (int i = SPACE; i < space; i++)
        printf(" ");
    printf("%d|\n", root->number);

    print_values(root->left, space);
}

void level_order(bst_node *root)
{

    queue_t *q = create_queue();
    enqueue(q, root);
}