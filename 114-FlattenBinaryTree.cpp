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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        
        TreeNode* mostRight = root;
        TreeNode* tmp = root;
        while(cur!=NULL){
            if(cur->left!=NULL){
                tmp = cur->left;
                mostRight = cur->left;
                while(mostRight->right!=NULL)
                    mostRight=mostRight->right;
                mostRight->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
