#include "unity.h"
#include "167.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_167(void)
{
    int nums[] = {2,7,11,15};
    int rtnSize, *rtn;
    rtn = twoSum(nums, 4, 9, &rtnSize);
    TEST_ASSERT_EQUAL_INT(2, rtnSize);
    if(rtn == NULL) {
        TEST_FAIL_MESSAGE("NULL returned");
    } else {
        TEST_ASSERT_EQUAL_INT(1, rtn[0]);
        TEST_ASSERT_EQUAL_INT(2, rtn[1]);
    }
    
}
