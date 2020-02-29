/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//递归，判断当前节点，再递归判断左右子树
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p&&!q) return true;
    else if(!p&&q||!q&&p) return false;
    if(p->val!=q->val) return false;
    else return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
}