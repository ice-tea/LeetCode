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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL || root->left==NULL)
            return root;
        stack<TreeNode*> lefts;
        TreeNode* l = root;
        while(l!=NULL){
            lefts.push(l);
            l=l->left;
        }
        TreeNode* res = lefts.top();
        l = res;
        lefts.pop();
        //cout<<l->val<<endl;
        while(l!=root){
            TreeNode* tmp = lefts.top();
            //cout<<tmp->val<<endl;
            l->left = tmp->right;
            l->right = tmp;
            l = tmp;
            lefts.pop();
        }
        //Remeber!!
        l->left = NULL;
        l->right=NULL;
        return res;
    }
};
