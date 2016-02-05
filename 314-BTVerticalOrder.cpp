class Solution {
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        if(root==nullptr) {
            return vector<vector<int> > ();
        }
        int l = leftmoststep(root), r = rightmoststep(root);
        vector<vector<int> > ans(l+r-1, vector<int>());
        queue<pair<TreeNode*, int> > que;
        que.push(make_pair(root, l-1));
        while(!que.empty()) {
            auto r = que.front();
            que.pop();
            ans[r.second].push_back(r.first->val);
            if(r.first->left) {
                que.push(make_pair(r.first->left, r.second-1));
            }
            if(r.first->right) {
                que.push(make_pair(r.first->right, r.second+1));
            }
        }
        return ans;
    }
private:
    // following method is used to calculate width of the tree: 
    //                 distance of root to left most node
    //                 distance of root to right most node
    int leftmoststep(TreeNode* root) {
        if(root==nullptr) return 0;
        return max(leftmoststep(root->left)+1, leftmoststep(root->right)-1);
    }
    int rightmoststep(TreeNode* root) {
        if(root==nullptr) return 0;
        return max(rightmoststep(root->left)-1, rightmoststep(root->right)+1);
    }
};


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
private:
    int L=0;
    int R=0;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if(root==NULL){
            vector<int> tmp;
            vector<vector<int>> res;
            return res;
        }

        int a=0;
        dfs(root,a);
        cout<<L<<R<<endl;
        int len = R-L+1;
        
        vector<int> tmp;
        vector<vector<int>>res (len,tmp);
        
        queue<TreeNode*> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(-L);
        TreeNode* cur;
        int curL;
        while(!q1.empty()){
            cur = q1.front();
            curL = q2.front();
            res[curL].push_back(cur->val);
            
            q1.pop();
            q2.pop();
            if(cur->left!=NULL){
                q1.push(cur->left);
                q2.push(curL-1);
            }
            if(cur->right!=NULL){
                q1.push(cur->right);
                q2.push(curL+1);
            }
        }
        return res;
    }

    void dfs(TreeNode* root, int a){
        if(root==NULL)
            return;
        L = min(L,a);
        R = max(R,a);
        dfs(root->left,a-1);
        dfs(root->right,a+1);
    }
};
