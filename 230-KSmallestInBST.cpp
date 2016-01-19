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
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        int res = 0;
        InorderT(root,num,k,res);
        return res;
    }
    void InorderT(TreeNode* root,int &num, int k, int &res){
        if(root ==NULL || num>k)
            return;
        InorderT(root->left,num, k, res);
        num++;
        if(k==num)
            res = root->val;
        InorderT(root->right,num, k, res);
    }
};
