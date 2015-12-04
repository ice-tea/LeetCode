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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> v;
        if(root==NULL)
            return res;
        findPath(root,res,v);
        return res;
    }
    void findPath(TreeNode* root,vector<string>&res,vector<int>v){
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            res.push_back(string_of(v));
            return;
        }
        
        if(root->left!=NULL)
            findPath(root->left,res,v);
        if(root->right!=NULL)
            findPath(root->right,res,v);
        return;
    }
    string string_of(vector<int>v){
        string s = string_of(v[0]);
        for(int i=1;i<v.size();++i){
            s = s + "->" + string_of(v[i]);
        }
        return s;
    }
    string string_of(int num){
        bool minus = false;
        string s = "";
        if(num<0){
            minus = true;
            num = 0-num;
        }
        while(num>=10){
            s = char('0' + num%10) + s;
            num/=10;
        }
        s = char('0' + num%10) + s;
        return (minus)? ("-"+s):s;
    }
};
