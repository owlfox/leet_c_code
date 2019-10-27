#include "unity.h"
#include "977.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_977_1(void)
{
    int nums[] = {-4,-1,0,3,10}; //[0,1,9,16,100]
    int rtnSize, *rtn;
    rtn = sortedSquares(nums, 5, &rtnSize);
    TEST_ASSERT_EQUAL_INT(5, rtnSize);
    if(rtn == NULL) {
        TEST_FAIL_MESSAGE("NULL returned");
    } else {
        TEST_ASSERT_EQUAL_INT(0, rtn[0]);
        TEST_ASSERT_EQUAL_INT(1, rtn[1]);
        TEST_ASSERT_EQUAL_INT(9, rtn[2]);
        TEST_ASSERT_EQUAL_INT(16, rtn[3]);
        TEST_ASSERT_EQUAL_INT(100, rtn[4]);
    }
}


// Input: [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
void test_977_2(void)
{
    int nums[] = {-7,-3,2,3,11}; 
    int rtnSize, *rtn;
    rtn = sortedSquares(nums, 5, &rtnSize);
    TEST_ASSERT_EQUAL_INT(5, rtnSize);
    if(rtn == NULL) {
        TEST_FAIL_MESSAGE("NULL returned");
    } else {
        TEST_ASSERT_EQUAL_INT(4, rtn[0]);
        TEST_ASSERT_EQUAL_INT(9, rtn[1]);
        TEST_ASSERT_EQUAL_INT(9, rtn[2]);
        TEST_ASSERT_EQUAL_INT(49, rtn[3]);
        TEST_ASSERT_EQUAL_INT(121, rtn[4]);
    }
}

void test_977_3(void)
{
    int nums[] = {0, 1, 2}; 
    int rtnSize, *rtn;
    rtn = sortedSquares(nums, 3, &rtnSize);
    TEST_ASSERT_EQUAL_INT(3, rtnSize);
    if(rtn == NULL) {
        TEST_FAIL_MESSAGE("NULL returned");
    } else {
        TEST_ASSERT_EQUAL_INT(0, rtn[0]);
        TEST_ASSERT_EQUAL_INT(1, rtn[1]);
        TEST_ASSERT_EQUAL_INT(4, rtn[2]);
    }
}

void test_977_4(void)
{
    int nums[] = {-20, -1, -1, 0}; 
    int rtnSize, *rtn;
    rtn = sortedSquares(nums, 4, &rtnSize);
    TEST_ASSERT_EQUAL_INT(4, rtnSize);
    if(rtn == NULL) {
        TEST_FAIL_MESSAGE("NULL returned");
    } else {
        TEST_ASSERT_EQUAL_INT(0, rtn[0]);
        TEST_ASSERT_EQUAL_INT(1, rtn[1]);
        TEST_ASSERT_EQUAL_INT(1, rtn[2]);
        TEST_ASSERT_EQUAL_INT(400, rtn[3]);
    }
}