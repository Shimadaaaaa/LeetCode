/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode *p, *q;
    p = head;
    q = p->next;
    while(q){
        while(q->val == p->val) {
            p->next = q->next;
            if(p->next != NULL){
                q = p->next;
            }
            else{
                return head;
            }
        }
        p = q;
        q = q->next;
    }
    return head;
}