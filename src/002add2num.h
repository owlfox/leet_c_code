#ifndef _002ADD2NUM_H
#define _002ADD2NUM_H
#include <stdbool.h>

 typedef struct ListNode {
     int val;
     struct ListNode *next;
  } list_ele_t;

typedef struct {
    list_ele_t *head;  /* Linked list of elements */
    /*
      You will need to add more fields to this structure
      to efficiently implement q_size and q_insert_tail
    */
   size_t length;
} queue_t;

/************** Operations on queue ************************/

queue_t *q_new();

void q_free(queue_t *q);

bool q_insert_head(queue_t *q, int t);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int getListInt(struct ListNode* l);

#endif // _002ADD2NUM_H
