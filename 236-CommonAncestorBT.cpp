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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>s1;
        vector<TreeNode*>s2;
        vector<TreeNode*>tmp1;
        find(root,p,tmp1,s1);
        vector<TreeNode*>tmp2;
        find(root,q,tmp2,s2);
        TreeNode* res = NULL;

        for(vector<TreeNode*>::iterator it1=s1.begin(), it2=s2.begin();
            it1!=s1.end() && it2!=s2.end() && *it1 == *it2; ++it1,++it2){
            res = *it1;
            cout<<(*it1)->val;
        }
        return res;
    }
    void find(TreeNode* root, TreeNode* t, vector<TreeNode*> &tmp, vector<TreeNode*> &res){
        tmp.push_back(root);
        if(root == NULL)
            return;
        if(root == t){
            res = tmp;
            return;
        }
        find(root->left, t, tmp, res);
        tmp.pop_back();
        find(root->right, t, tmp, res);
        tmp.pop_back();
    }
};
