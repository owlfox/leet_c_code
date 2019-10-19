#include "unity.h"
#include "002add2num.h"

queue_t *q1, *q2;

void setUp(void)
{
    q1 = q_new();
    q2 = q_new();
}

void tearDown(void)
{
    q_free(q1);
    q1 = NULL;
    q_free(q2);
    q2 = NULL;
}

void test_002add2num_list_ok2use(void)
{
    q_insert_head(q1, 1);
    q_insert_head(q1, 1);
    q_insert_head(q2, 2);
    TEST_ASSERT_EQUAL_INT(2, q1->length);
    TEST_ASSERT_EQUAL_INT(q1->head->val, 1);
    TEST_ASSERT_EQUAL_INT(q1->head->next->val, 1);
    TEST_ASSERT_EQUAL_INT(1, q2->length);
    TEST_ASSERT_EQUAL_INT(q2->head->val, 2);
}


void test_add2sum(void) {
    
    struct ListNode* l;
    
    q_insert_head(q1, 5);
    q_insert_head(q1, 3);
    q_insert_head(q1, 4);
    q_insert_head(q1, 2);
    
    q_insert_head(q2, 5);
    q_insert_head(q2, 4);
    q_insert_head(q2, 6);
    q_insert_head(q2, 5);
    
    l = addTwoNumbers(q1->head, q2->head);
    TEST_ASSERT_EQUAL_INT(10847, getListInt(l));
    
}

void test_add2sum_inbalnced(void) {
    
    struct ListNode* l;
    
    
    q_insert_head(q2, 4);
    q_insert_head(q2, 6);
    q_insert_head(q2, 5);
    
    l = addTwoNumbers(q1->head, q2->head);
    TEST_ASSERT_EQUAL_INT(465, getListInt(l));
}