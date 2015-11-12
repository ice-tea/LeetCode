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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> cur;
        cur.push_back(root);
        
        int s;
        int i;
        vector<int>tmp;
        while(!cur.empty()){
            s = cur.size()-1;
            i=0;
            if(!tmp.empty())
                tmp.erase(tmp.begin(),tmp.begin()+tmp.size());
            while(s>=0){
                if(cur[0]!=NULL){
                    tmp.push_back(cur[0]->val);
                    cur.push_back(cur[0]->left);
                    cur.push_back(cur[0]->right);
                }
                cur.erase(cur.begin());
                s--;
            }
            if(!tmp.empty())
                res.push_back(tmp);
        }
        return res;
    }
};
