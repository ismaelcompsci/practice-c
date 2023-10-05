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

bst_node *get_min(bst_node *root)
{

    if (root == NULL)
    {
        logger(ERROR_MODE, "TREE IS EMPTY\n");
        // exit(EXIT_FAILURE);
        return NULL;
    }
    bst_node *current = root;
    while (current->left)
    {
        current = current->left;
    }

    return current;
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

bst_node *get_successor(bst_node *root, int data)
{

    // O(h)
    bst_node *current = r_search(root, data);

    if (current == NULL)
        return NULL;

    // case 1 : if node has right subtree
    if (current->right != NULL)
        return get_min(current->right);
    // case 2: no right subtree
    else
    {
        bst_node *successor = NULL;
        bst_node *ancestor = root;

        while (ancestor != current)
        {
            if (current->number < ancestor->number)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }

        return successor;
    }
}

void delete_tree(bst_node *root)
{
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
    root = NULL;
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

bool is_bst(bst_node *root)
{
    return is_bst_util(root, INT8_MIN, INT8_MIN);
}

bool is_bst_util(bst_node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->number > minValue && root->number < maxValue && is_bst_util(root->left, minValue, root->number) && is_bst_util(root->right, root->number, maxValue))
        return true;

    return false;
}

/* Level Order Traversal */
int get_node_count(bst_node *root)
{

    if (root == NULL)
        return -1;

    queue_t *q = create_queue(sizeof(bst_node));
    enqueue(q, root);

    int count = 1;

    while (!empty(q))
    {
        bst_node *current = (bst_node *)dequeue(q);
        // printf("%i\n", current->number);

        if (current->left != NULL)
        {

            enqueue(q, current->left);
            count++;
        }

        if (current->right != NULL)
        {

            enqueue(q, current->right);
            count++;
        }
    }

    return count;
}

bst_node *delete_value(bst_node *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (value < root->number)
        root->left = delete_value(root->left, value);
    else if (value > root->number)
        root->right = delete_value(root->right, value);
    else
    {
        // case 1: no child
        if (root->left == NULL && root->right == NULL)
        {

            free(root); // free from heap
            root = NULL;
        }
        // case 2: one chlid
        else if (root->left == NULL)
        {
            bst_node *tmp = root;
            root = root->right;

            free(root);
        }
        else if (root->right == NULL)
        {
            bst_node *tmp = root;
            root = root->left;

            free(root);
        }
        // case 3: two children
        else
        {
            bst_node *temp = get_min(root->right);
            root->number = temp->number;

            root->right = delete_value(root->right, temp->number);
        }
    }
    return root;
}

/*--------------------* Different Implementations *-------------------------------------------------------------------------------------------------*/
/**
 * each node can at most have 2 children
 * for each node in left subtree is lessor and
 * value of all nodes in right subtree is greater
 */
bool is_binary_search_tree(bst_node *root)
{
    if (root == NULL)
        return true;

    if (is_subtree_lesser(root->left, root->number) && is_subtree_greater(root->right, root->number) && is_binary_search_tree(root->left) && is_binary_search_tree(root->right))
        return true;

    return false;
}

bool is_subtree_lesser(bst_node *root, int value)
{
    if (root == NULL)
        return true;

    if (root->number <= value && is_subtree_lesser(root->left, value) && is_subtree_lesser(root->right, value))
        return true;

    return false;
}
bool is_subtree_greater(bst_node *root, int value)
{
    if (root == NULL)
        return true;

    if (root->number >= value && is_subtree_greater(root->left, value) && is_subtree_greater(root->right, value))
        return true;

    return false;
}

bst_node *r_search(bst_node *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (root->number == value)
        return root;
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

void pre_order(bst_node *root)
{

    if (root == NULL)
        return;

    printf("%i\n", root->number);
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(bst_node *root)
{
    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    printf("%i\n", root->number);
}

void in_order(bst_node *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    printf("%i ", root->number);
    in_order(root->right);
}

void traverse(bst_node *root)
{
    printf("in order traversal: ");
    in_order(root);
    printf("\n");

    printf("post order traversal: ");
    post_order(root);
    printf("\n");

    printf("pre order traversal: ");
    pre_order(root);
    printf("\n");
}