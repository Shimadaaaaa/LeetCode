/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//加define快...
#define max(a, b) (a>b ? a: b)

int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    else{
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left+1, right+1);
    }

}