#include "../log/log.h"
#include "queue.h"

void run_all_tests()
{
    test_empty();
    test_all();

    logger(SUCCESS, "ALL TESTS PASSED\n");
}

void test_empty()
{
    queue_t *q = create_queue(sizeof(int));

    assert(empty(q));

    destroy_queue(q);
    logger(SUCCESS, "empty PASSED\n");
}

void test_all()
{
    queue_t *q = create_queue(sizeof(int));

    enqueue(q, 100);
    assert(empty(q) == false);
    assert(dequeue(q) == 100);
    enqueue(q, 200);
    enqueue(q, 300);
    enqueue(q, 400);
    assert(dequeue(q) == 200);
    assert(dequeue(q) == 300);
    assert(dequeue(q) == 400);

    assert(empty(q));

    destroy_queue(q);
    logger(SUCCESS, "enqueue & dequeue PASSED\n");
}