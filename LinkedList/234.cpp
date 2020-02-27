/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//反转一半链表，再对比
int get_len(struct ListNode *head){
    int length = 0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}

struct ListNode* reverse(struct ListNode *head, int n){
    struct ListNode ret, *p=head, *q;
    while(n--) p = p->next;
    ret.next = NULL;
    while(p){
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head){
    int len = get_len(head);
    struct ListNode *p = head, *q = reverse(head, len/2);
    while(q){
        if(p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}