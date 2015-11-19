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
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum = 0;
        int tmp = 0;
        sumHelp(root,sum, tmp);
        return sum;
    }
    void sumHelp(TreeNode* root, int &sum, int tmp) {
        tmp = tmp*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+= tmp;
            return;
        }
        else if(root->left==NULL)
            sumHelp(root->right,sum,tmp);
        else if(root->right==NULL)
            sumHelp(root->left,sum,tmp);
        else{
            sumHelp(root->left,sum,tmp);
            sumHelp(root->right,sum,tmp);
        }
    }
};
