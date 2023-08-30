#include "linked_list.h"
#include "../log/log.h"

void run_all_tests()
{
    test_size();
    test_push_front();
    test_empty();
    test_value_at();
    test_pop_front();
    test_push_back();
    test_pop_back();
    test_front();
    test_back();
    test_insert();
    test_erase();
    test_value_n_from_end();
    test_reverse();
    test_remove_value();
}

void test_size()
{
    node_t *head = NULL;

    assert(size(head) == 0);

    node_t *first = malloc(sizeof(node_t));
    check_address(first);

    first->data = 1;
    first->next = NULL;

    head = first;

    assert(size(head) == 1);

    logger(SUCCESS, "size passed\t");
    print_list(head);

    destroy_linked_list(head);
}

void test_push_front()
{
    node_t *head = NULL;
    push_front(&head, 10);

    assert(size(head) == 1);

    push_front(&head, 8);
    push_front(&head, 12);

    assert(size(head) == 3);

    logger(SUCCESS, "push_front passed\t");
    print_list(head);

    destroy_linked_list(head);
}

void test_empty()
{
    node_t *head = NULL;

    assert(empty(head));

    logger(SUCCESS, "empty passed\n");
    destroy_linked_list(head);
}

void test_value_at()
{
    node_t *head = NULL;

    push_front(&head, 7);
    assert(value_at(head, 0) == 7);

    logger(SUCCESS, "value_at passed\t");
    print_list(head);

    destroy_linked_list(head);
}

void test_pop_front()
{
    node_t *head = NULL;

    push_front(&head, 9);
    push_front(&head, 25);
    assert(pop_front(&head) == 25);
    assert(pop_front(&head) == 9);

    logger(SUCCESS, "pop_front passed\t");
    print_list(head);

    destroy_linked_list(head);
}

void test_push_back()
{
    node_t *head = NULL;

    push_back(&head, 99);
    assert(value_at(head, 0) == 99);

    push_back(&head, 88);
    assert(value_at(head, 1) == 88);

    logger(SUCCESS, "push_back passed\t");
    print_list(head);

    destroy_linked_list(head);
}

void test_pop_back()
{
    node_t *head = NULL;

    push_back(&head, 122);
    assert(pop_back(&head) == 122);

    push_back(&head, 564);
    push_back(&head, 72);
    assert(pop_back(&head) == 72);
    assert(pop_back(&head) == 564);

    assert(size(head) == 0);

    logger(SUCCESS, "pop_back passed\n");
    destroy_linked_list(head);
}

void test_front()
{
    node_t *head = NULL;

    push_front(&head, 7);
    assert(front(head) == 7);

    push_front(&head, 6);
    assert(front(head) == 6);

    logger(SUCCESS, "front passed\n");
    destroy_linked_list(head);
}

void test_back()
{
    node_t *head = NULL;

    push_back(&head, 77);
    assert(back(head) == 77);

    push_back(&head, 42);
    assert(back(head) == 42);

    pop_back(&head);
    assert(back(head) == 77);

    logger(SUCCESS, "back passed\n");
    destroy_linked_list(head);
}

void test_insert()
{
    node_t *head = NULL;

    insert(&head, 0, 5);
    insert(&head, 0, 3);
    insert(&head, 1, 4);
    insert(&head, 3, 6);

    assert(value_at(head, 0) == 3);
    assert(value_at(head, 1) == 4);
    assert(value_at(head, 2) == 5);
    assert(value_at(head, 3) == 6);

    logger(SUCCESS, "insert passed\n");
    destroy_linked_list(head);
}

void test_erase()
{
    node_t *head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    erase(&head, 0);
    assert(value_at(head, 0) == 2);
    assert(size(head) == 2);

    erase(&head, 1);
    assert(value_at(head, 0) == 2);
    assert(size(head) == 1);

    erase(&head, 0);
    assert(size(head) == 0);

    logger(SUCCESS, "erase passed\n");
    destroy_linked_list(head);
}

void test_value_n_from_end()
{
    node_t *head = NULL;

    push_back(&head, 7);
    assert(value_n_from_end(head, 1) == 7);

    push_back(&head, 8);
    assert(value_n_from_end(head, 2) == 7);
    assert(value_n_from_end(head, 1) == 8);

    logger(SUCCESS, "value_n_from_end passed\n");

    destroy_linked_list(head);
}

void test_reverse()
{
    node_t *head = NULL;

    push_back(&head, 4);
    reverse(&head); // 4 ->
    assert(value_at(head, 0) == 4);

    push_back(&head, 5);
    reverse(&head); // 5 -> 4 ->
    assert(value_at(head, 0) == 5);
    assert(value_at(head, 1) == 4);

    push_back(&head, 3);
    reverse(&head); // 3 -> 4 -> 5 ->
    assert(value_at(head, 0) == 3);
    assert(value_at(head, 1) == 4);
    assert(value_at(head, 2) == 5);
    logger(SUCCESS, "reverse passed\n");

    destroy_linked_list(head);
}

void test_remove_value()
{
    node_t *head = NULL;

    push_back(&head, 1);

    remove_value(&head, 1);
    assert(empty(head));
    remove_value(&head, 9); // won't be found

    push_back(&head, 1);
    push_back(&head, 2);
    remove_value(&head, 1);
    assert(size(head) == 1);
    assert(value_at(head, 0) == 2);

    push_back(&head, 3);
    push_back(&head, 4);

    remove_value(&head, 4);
    assert(size(head) == 2);
    assert(value_at(head, 1) == 3);
    logger(SUCCESS, "remove_value passed\n");

    destroy_linked_list(head);
}