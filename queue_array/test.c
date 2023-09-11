#include "../log/log.h"

void run_all_tests()
{
    test_empty();
    test_enqueue();
    test_dequeue();
    test_rotation();
    logger(SUCCESS, "ALL TESTS PASSED\n");
}

void test_empty()
{
    queue_t *q = create_queue();

    assert(empty(q));

    enqueue(q, 43);

    assert(empty(q) == false);

    free(q);
    logger(SUCCESS, "empty PASSED\n");
}

void test_enqueue()
{
    queue_t *q = create_queue();

    enqueue(q, 100);
    enqueue(q, 200);
    enqueue(q, 300);
    enqueue(q, 400);
    enqueue(q, 500);

    assert(full(q));

    free(q);
    logger(SUCCESS, "enqueue PASSED\n");
}

void test_dequeue()
{
    queue_t *q = create_queue();

    assert(empty(q));

    enqueue(q, 100);
    assert(empty(q) == false);
    assert(dequeue(q) == 100);

    assert(empty(q));

    free(q);
    logger(SUCCESS, "dequeue PASSED\n");
}

void test_rotation()
{
    queue_t *q = create_queue();

    enqueue(q, 100);
    enqueue(q, 200);
    assert(dequeue(q) == 100);
    enqueue(q, 300);
    enqueue(q, 400);
    assert(dequeue(q) == 200);
    enqueue(q, 500);
    enqueue(q, 600);
    enqueue(q, 700);

    assert(full(q));

    free(q);
    logger(SUCCESS, "rotation PASSED\n");
}