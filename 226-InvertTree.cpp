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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        invertHelp(root);
        return root;
    }
    void invertHelp(TreeNode* root) {
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if(root->left!=NULL)
            invertHelp(root->left);
        if(root->right!=NULL)
            invertHelp(root->right);
    }
};
