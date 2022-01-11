#include<stdlib.h>
#include<stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    ListNode dummyroot = {0,NULL};
    ListNode *curr;
    ListNode *l;
    int carry;
    int sum;
    
    curr = &dummyroot;
    carry = 0;
    
    while(l1 && l2){
        curr->next = malloc(sizeof(ListNode));
        curr = curr->next;
        if(!curr){
            return NULL;
        }
        
        sum = l1->val + l2->val + carry;
        curr->val = sum%10;
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
    }

    l = l1 ? l1:l2;
    
    while(l){
        curr->next = malloc(sizeof(ListNode));
        curr = curr->next;
        if(!curr){
            return NULL;
        }
        
        sum = l->val + carry;
        curr->val = sum%10;
        carry = sum/10;
        l = l->next;
    }
    
    if(carry){
        curr->next = malloc(sizeof(ListNode));
        curr = curr->next;
        if(!curr){
            return NULL;
        }
        curr->val = carry;
    }
    
    curr->next = NULL;
    return dummyroot.next;
}

int main(void){
    ListNode a1 = {2,NULL};
    ListNode a2 = {4,NULL};
    ListNode a3 = {3,NULL};

    ListNode b1 = {5,NULL};
    ListNode b2 = {6,NULL};
    ListNode b3 = {4,NULL};

    ListNode *result;

    a1.next = &a2;
    a2.next = &a3;

    b1.next = &b2;
    b2.next = &b3;

    result = addTwoNumbers(&a1, &b1);
    if(result){
        ListNode *c=result, *p;
        while(c){
            printf("%d", c->val);
            p = c;
            c = c->next;
            free(p);
        }
        printf("\n");
    }else{
        printf("Empty result\n");
    }

    return 0;
}
