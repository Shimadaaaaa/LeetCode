/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//虚拟头节点

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *pre_node =(struct ListNode *)malloc(sizeof(struct ListNode));
    pre_node->next = head;
    struct ListNode *m = pre_node;
    struct ListNode *p, *q;
    while(m->next != NULL){
        p = m->next;
        q = p->next;
        if(q == NULL) break;
        m->next = q;
        p->next = q->next;
        q->next = p;
        m = p;
    }
    return pre_node->next;
}