/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//得到树的深度
int get_depth(struct TreeNode* root){
    if(root == NULL) return 0;
    int l = get_depth(root->left), r = get_depth(root->right);
    return (l>r? l : r) + 1; 
}

//得到树每层节点的个数
void get_cnt(struct TreeNode* root, int k, int *cnt){
    if(root == NULL) return ;
    cnt[k] += 1;
    get_cnt(root->left, k+1, cnt);
    get_cnt(root->right, k+1, cnt);
    return ;
}

//向ret里存数
void get_result(struct TreeNode* root, int k, int *cnt, int **ret){
    if(root == NULL) return ;
    ret[k][cnt[k]++] = root->val; //cnt[k]++记录下个该放数的位置
    get_result(root->left, k+1, cnt, ret);
    get_result(root->right, k+1, cnt, ret);
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = get_depth(root); //先知道树的深度
    int **ret = (int **)malloc(sizeof(int *) * depth);
    int *cnt = (int *)calloc(depth, sizeof(int));//用calloc清空
    get_cnt(root, 0, cnt);
    for(int i=0; i<depth; i++){
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;  //这里清零，下次继续做标志位使用
    }
    get_result(root, 0, cnt, ret);
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}