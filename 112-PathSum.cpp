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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        return check(root,sum);
    }
    int check(TreeNode* root, int sum) {
        if(root->left ==NULL && root->right ==NULL)
            return sum==root->val;
        if(root->left ==NULL)
            return check(root->right,sum-root->val);
        if(root->right ==NULL)
            return check(root->left,sum-root->val);
        return check(root->left,sum-root->val)||check(root->right,sum-root->val);
    }
};
