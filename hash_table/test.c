#include "../log/log.h"

void run_all_tests()
{
    test_exists();
    test_add_get();
    test_add_remove();
}

void test_exists()
{
    hash_table *states = create_table(TABLE_SIZE);
    assert(exists(states, "Texas") == false);

    add(states, "Texas", "Austin");

    logger(INFO, "finding Texas value\n");
    assert(exists(states, "Texas") == true);

    // destroy_table(states);

    logger(SUCCESS, "exists passed\n");
}

void test_add_get()
{
    hash_table *states = create_table(TABLE_SIZE);

    add(states, "Louisiana", "Baton Rouge");

    add(states, "Maine", "Augusta");

    key_value *capital1 = get(states, "Louisiana");
    assert(strcmp(capital1->value, "Baton Rouge") == 0);

    // add LA again, with new capital
    add(states, "Louisiana", "New Orleans");

    // now capital should be Nawlins
    key_value *capital2 = get(states, "Louisiana");
    assert(strcmp(capital2->value, "New Orleans") == 0);

    // destroy_table(states);
    logger(SUCCESS, "add & get passed");
}

void test_add_remove()
{
    hash_table *states = create_table(TABLE_SIZE);
    add(states, "California", "Sacramento");
    assert(exists(states, "California") == true);
    remove_(states, "California");
    assert(exists(states, "California") == false);

    // destroy_table(states);
    logger(SUCCESS, "remove passed");
}