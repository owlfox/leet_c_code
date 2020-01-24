#include "unity.h"
#include "uva1585.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_1st(void)
{
    TEST_ASSERT_EQUAL_INT(10, getScore("OOXXOXXOOO"));
    TEST_ASSERT_EQUAL_INT(9, getScore("OOXXOOXXOO"));
    TEST_ASSERT_EQUAL_INT(7, getScore("OXOXOXOXOXOXOX"));
    TEST_ASSERT_EQUAL_INT(55, getScore("OOOOOOOOOO"));
    TEST_ASSERT_EQUAL_INT(30, getScore("OOOOXOOOOXOOOOX"));
}