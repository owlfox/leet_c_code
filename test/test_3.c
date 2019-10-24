#include "unity.h"
#include "3.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_3_NeedToImplement(void)
{   
    TEST_ASSERT_EQUAL_INT(3,lengthOfLongestSubstring("abcabcbb"));
    TEST_ASSERT_EQUAL_INT(1,lengthOfLongestSubstring("bbbbb"));
    TEST_ASSERT_EQUAL_INT(3,lengthOfLongestSubstring("pwwkew"));
}
