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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preHelp(root,res);
        return res;
    }
    void preHelp(TreeNode* root, vector<int>& tmp){
        if(root==NULL)
            return;
        tmp.push_back(root->val);
        preHelp(root->left,tmp);
        preHelp(root->right,tmp);
    }
    
};
