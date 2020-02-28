/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//链表拼接，补齐长度
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ha = headA;
    struct ListNode *hb = headB;
    while(ha != hb){
        if(ha != NULL){
            ha = ha->next;
        }
        else{
            ha = headB;
        }
        if(hb != NULL){
            hb = hb->next;
        }
        else{
            hb = headA;
        }
    }
    return ha;
}