
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "002add2num.h"

queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    if(q == NULL) return q;
    /* What if malloc returned NULL? */
    q->head = NULL;
    q->length = 0;
    return q;
}


static list_ele_t *l_new(int t){
    list_ele_t *newh;
    if((newh = malloc(sizeof(list_ele_t))) == NULL) return NULL;
    
    newh->val = t;
    newh->next = NULL;
    return newh;
}

bool q_insert_head(queue_t *q, int t) 
{
    list_ele_t *newh;

    /* What should you do if the q is NULL? */
    if(q == NULL || (newh = l_new(t)) == NULL) return false;

    
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    if(q->length == 0) {
      newh->next = NULL;
    } else {

      newh->next = q->head;
    }
    
    q->head = newh;
    q->length += 1;
    
    return true;
}

void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *current;
    if(q == NULL) return;
    while(q->length != 0){
      
      current = q->head;


      q->head = current->next;
      q->length -= 1;

      free(current);
      current = NULL;
    }
    if(q != NULL) free(q);
    
}

int getListInt(struct ListNode* l){
    int rtn = 0;
    for(int base=1 ;l!=NULL;l=l->next){
        rtn += base*l->val;
        base *= 10;
    }
    return rtn;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum, carry=0;
    int len = 0;
    
    struct ListNode* node;
    struct ListNode* tail;
    struct ListNode* head;
    tail = NULL;
    
    do {
        
        node = malloc(sizeof(struct ListNode));
        node->next = NULL;
        
        sum = carry + (l1?l1->val:0) +
                      (l2?l2->val:0);
        carry = sum / 10;
        node->val = sum % 10;
        if(len == 0) {
            tail = node;
            head = node;
        } 
        else {
          tail->next = node;
          tail = node;
        }
        len += 1;
        
        l1 = l1?l1->next:NULL; 
        l2 = l2?l2->next:NULL;
    } while(l1||l2);

    if (carry) {
        node = malloc(sizeof(struct ListNode));
        node->next = NULL;
        tail->next = node;
        node->val = carry;
    }

    return head;
}


