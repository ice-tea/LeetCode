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
    int maxDepth(TreeNode* root) {
        return maxHelp(root);
    }
    int maxHelp(TreeNode *root){
        if(root==NULL)
            return 0;
        return 1+max(maxHelp(root->left),maxHelp(root->right));
    } 
};
