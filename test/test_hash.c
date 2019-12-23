#include "unity.h"
#include "hash.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hash_101(void)
{
    add_user(3, "Michael");
    struct my_struct *user = find_user(3);
    printf("%s", user->name);

}
