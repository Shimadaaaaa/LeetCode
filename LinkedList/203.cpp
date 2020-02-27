/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int goal){
    struct ListNode *pre_node =(struct ListNode *)malloc(sizeof(struct ListNode));
    pre_node->next = head;
    struct ListNode *p = pre_node;
    while(p->next != NULL){
        if(p->next->val == goal){
            p->next = p->next->next;
        }
        else{
            p = p->next;
        }
    }
    return pre_node->next;
}