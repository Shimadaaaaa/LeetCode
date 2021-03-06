/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//定义一个递归函数，判断两棵树是否镜像对称
bool isMirror(struct TreeNode *t1, struct TreeNode *t2){
    if(t1 == NULL && t2 == NULL) return true;
    else if(t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);  
}



bool isSymmetric(struct TreeNode* root){
    return isMirror(root, root);
}