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
        vector<TreeNode*>tmp;
        find(root,p,tmp,s1);
        find(root,q,tmp,s2);
        TreeNode* res = NULL;
        for(vector<TreeNode*>::iterator it1=s1.begin(), it2=s2.begin();
            it1!=s1.end() && it2!=s2.end() && *it1 == *it2; ++it1,++it2){
            res = *it1;
        }
        return res;
    }
    void find(TreeNode* root, TreeNode* t, vector<TreeNode*> tmp, vector<TreeNode*> &res){
        if(root == NULL)
            return;
        tmp.push_back(root);
        if(root == t){
            res = tmp;
            return;
        }
        tmp.push_back(root);
        find(root->left, t, tmp, res);
        find(root->right, t, tmp, res);
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        if (p == NULL || q == NULL) return NULL;

        int minv = p->val;
        int maxv = q->val;
        if (minv > maxv)
            maxv = minv, minv = q->val;

        while (1)
        {
            if (root->val > maxv)
                root = root->left;
            else if (root->val < minv)
                root = root->right;
            else 
                return root;
        }
    }
