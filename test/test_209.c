#include "unity.h"
#include "209.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_209_NeedToImplement(void)
{
    int s = 7, nums[] = {2,3,1,2,4,3};
    TEST_ASSERT_EQUAL_INT(2,minSubArrayLen(s, nums, 6));
}
