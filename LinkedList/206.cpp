/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//头插法
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode pre_node;
    struct ListNode *p = head, *q;
    pre_node.next = NULL;
    while(p != NULL){
        q = p->next;
        p->next = pre_node.next;
        pre_node.next = p;
        p = q;
    }
    return pre_node.next;  
}