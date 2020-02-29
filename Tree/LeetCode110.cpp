/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int get_depth(struct TreeNode* root){
    if(root == NULL) return 0;
    int l = get_depth(root->left), r = get_depth(root->right);
    if(l == -2 || r == -2 || abs(l-r)>1) return -2; //当左右子树高度差大于1，则记高度为-2， 这样最后树的高度也为-2，判断其不是平衡树
    return (l>r? l : r) + 1; 
}

bool isBalanced(struct TreeNode* root){
    return get_depth(root) >= 0;
}