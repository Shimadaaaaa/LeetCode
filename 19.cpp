/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//双指针法

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *end_node = head;
    for(int i=0; i<n; i++){
        end_node = end_node->next;
    }
    struct ListNode *delete_node = head;
    struct ListNode *current_node = head;
    if(end_node == NULL) head = head->next;
    while(end_node != NULL){
        end_node = end_node->next;
        current_node = delete_node;
        delete_node = delete_node->next;
    }
    current_node->next = delete_node->next;
    return head;
}