#include "binary_search_tree.h"
#include "../log/log.h"

void run_all_tests();
void test_insert();
void test_r_insert();
void test_height();
void test_level_order();
void test_delete();

void run_all_tests()
{
    test_insert();
    test_r_insert();
    test_height();
    test_level_order();
    test_delete();

    logger(SUCCESS, "ALL TESTS PASSED\n");
}

void test_insert()
{

    bst_node *root = create_tree(10);
    insert(&root, 9);

    assert(is_in_tree(root, 9) == true);
    assert(is_in_tree(root, 10) == true);
    assert(is_in_tree(root, 11) == false);

    int min = get_min(root)->number;

    logger(SUCCESS, "insert PASSED\n");
}

void test_r_insert()
{

    bst_node *root = create_tree(10);
    r_insert(root, 9);

    assert(is_in_tree(root, 9) == true);
    assert(is_in_tree(root, 10) == true);
    assert(is_in_tree(root, 11) == false);

    logger(SUCCESS, "r_insert PASSED\n");
}

void test_height()
{
    bst_node *root = create_tree(10);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 8);
    insert(&root, 11);

    int h = get_height(root);
    assert(3 == h);

    logger(SUCCESS, "get_height PASSED\n");
}

void test_level_order()
{

    bst_node *root = create_tree(10);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 8);
    insert(&root, 11);

    int h = get_height(root);
    assert(3 == h);

    int count = get_node_count(root);
    assert(count == 5);

    logger(SUCCESS, "level_order PASSED\n");
}

void test_delete()
{
    bst_node *root = create_tree(15);
    insert(&root, 10);
    insert(&root, 8);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 11);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 27);
    insert(&root, 17);
    insert(&root, 16);

    // print_values(root, 0);

    delete_tree(root);

    logger(SUCCESS, "delete PASSED\n");
}