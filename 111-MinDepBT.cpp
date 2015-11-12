/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root ==NULL)
            return 0;
        return minHelp(root);
    }
    int minHelp(TreeNode *root){
        if(root->left==NULL && root->right==NULL)
            return 1;
        if(root->left==NULL)
            return 1+minHelp(root->right);
        if(root->right==NULL)
            return 1+minHelp(root->left);
        return 1+min(minHelp(root->left),minHelp(root->right));
    } 
};
