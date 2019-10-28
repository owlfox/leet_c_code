#include "unity.h"
#include <stdlib.h>
#include "13_3sum.h"
int** columnSize;
void setUp(void)
{
    columnSize = (int**) malloc(sizeof(int*));
}

void tearDown(void)
{
    free(columnSize);
}

void test_13_3sum00(void)
{
//     Given array nums = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int rtnSize, **rtn;
    int *array, *sizeArray;
    *columnSize = nums;
    // printf("%p??%d\n",*columnSize, (*columnSize)[2]);
    // printf("test %p, %p: \n", columnSize, *columnSize);
    rtn = threeSum(nums, 6, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(2, rtnSize);
    if(rtn == NULL) {
        TEST_FAIL_MESSAGE("NULL returned");
    } else {
        array = *(rtn);
        TEST_ASSERT_EQUAL_INT(-1, array[0]);
        TEST_ASSERT_EQUAL_INT(-1, array[1]);
        TEST_ASSERT_EQUAL_INT(2, array[2]);
        free(array);
        array = *(rtn+1);
        TEST_ASSERT_EQUAL_INT(-1, array[0]);
        TEST_ASSERT_EQUAL_INT(0, array[1]);
        TEST_ASSERT_EQUAL_INT(1, array[2]);
        free(array);
        free(rtn);
        // sizeArray = *(columnSize);
        
        // printf("test %p: \n", columnSize);
        TEST_ASSERT_EQUAL_INT(3, (*columnSize)[0]);
        // TEST_ASSERT_EQUAL_INT(3, **(columnSize+1));
        
        // for(int i=0; i<rtnSize; i++){
        //     printf("%p: \n", *(rtn+i));
        //     for(int j=0; j<3; j++){
        //         printf("%d ", *(*(rtn+i)+j));
        //     }
        //     printf("\n");
        // }
    }
}


void test_13_3sum1(void)
{
    int nums[] = {-1, -1, -1, -1, -1, -1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 6, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(0, rtnSize);
    
}

void test_13_3sum2(void)
{
    int nums[] = {0, 0, 0, -1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 4, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(1, rtnSize);
    array = *(rtn);
    TEST_ASSERT_EQUAL_INT(0, array[0]);
    TEST_ASSERT_EQUAL_INT(0, array[1]);
    TEST_ASSERT_EQUAL_INT(0, array[2]);
    TEST_ASSERT_EQUAL_INT(3, (*columnSize)[0]);
    
}
void test_13_3sum3(void)
{
    int nums[] = {1, 1, 1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 3, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(0, rtnSize);
    
}
void test_13_3sum4(void)
{
    int nums[] = {1, 1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 2, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(0, rtnSize);
    
}
void test_13_3sum5(void)
{
    int nums[] = {-1, 1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 2, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(0, rtnSize);
    
}
void test_13_3sum6(void)
{
    int nums[] = {-1, -1, -1, 1, 1, 1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 6, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(0, rtnSize);
    
}

void test_13_3sum7(void)
{
    int nums[] = {-1, -1, 0, 1, 1, 1};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 6, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(1, rtnSize);
    
}

void test_13_3sum8(void)
{
    int nums[] = {-2, 0, 0, 2, 2};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 5, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(1, rtnSize);
    
}
void test_13_3sum9(void)
{
    int nums[] = {-2, 0, 1, 1, 2};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 5, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(2, rtnSize);
    
}

void test_13_3sum10(void)
{
    int nums[] = {3,0,-2,-1,1,2};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 6, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(3, rtnSize);
    
}

// [2,0,-2,-5,-5,-3,2,-4]
void test_13_3sum11(void)
{
    int nums[] = {-5,-5,-4,-3,-2,0,2,2};
    int rtnSize, **rtn;
    int *array;
    rtn = threeSum(nums, 8, &rtnSize, columnSize);
    TEST_ASSERT_EQUAL_INT(2, rtnSize);
    
}