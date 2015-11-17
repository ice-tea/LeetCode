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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        check(root,sum,tmp,res);
        return res;
    }
    void check(TreeNode* root, int sum,vector<int> &tmp,vector<vector<int>>&res) {
        tmp.push_back(root->val);
        sum-=root->val;
        if(root->left ==NULL && root->right ==NULL){
            if(sum==0)
                res.push_back(tmp);
        }
        else if(root->left ==NULL)
            check(root->right,sum,tmp,res);
        else if(root->right ==NULL)
            check(root->left,sum,tmp,res);
        else{
            check(root->left,sum,tmp,res);
            check(root->right,sum,tmp,res);
        }
        tmp.erase(tmp.begin()+tmp.size()-1);
    }
};
