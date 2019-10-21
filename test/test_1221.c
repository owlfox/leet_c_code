#include "unity.h"
#include "1221.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_1221_NeedToImplement(void)
{
    TEST_ASSERT_EQUAL_INT(4,balancedStringSplit("RLRRLLRLRL"));
    TEST_ASSERT_EQUAL_INT(3,balancedStringSplit("RLLLLRRRLR"));
    TEST_ASSERT_EQUAL_INT(1,balancedStringSplit("LLLLRRRR"));
}



