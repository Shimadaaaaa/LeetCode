/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//快慢指针，相遇后，一个不动，一个再走一圈，得到环长度

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if(p == NULL) return NULL;
    do{
        p = p->next;
        q = q->next;
        if(q == NULL || q->next == NULL) return NULL;
        q = q->next;
    }while(p != q);
    int cnt = 0;
   do{
        q = q->next;
        cnt ++;
    } while(p != q);
    p = head, q = head;
    while(cnt --) q = q->next;
    while(p != q) p = p->next, q = q->next;
    return p;
}