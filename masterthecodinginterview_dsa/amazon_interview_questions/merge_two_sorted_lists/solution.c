
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    
    struct ListNode *l1=list1;
    struct ListNode *l2=list2;
    struct ListNode dummyhead;
    struct ListNode *curr, *l;
    
    curr = &dummyhead;
    
    while(l1 && l2){
        if(l1->val < l2->val){
            curr->next = l1;
            l1 = l1->next;
        }else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    l = l1 ? l1:l2;
    while(l){
        curr->next = l;
        l = l->next;
        curr = curr->next;
    }
    
    return dummyhead.next;
}
