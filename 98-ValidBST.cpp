/**
 *definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       vector<int> v = inorderTraversal(root);
       int s=v.size();
       for(int i=0;i<s-1;i++){
           if(v[i]>=v[i+1])
                return false;
       }
       return true;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root,res);
        return res;
    }
    void inorderTraversal(TreeNode* root, vector<int> &v) {
        if(root==NULL)
            return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
};
