/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> tmp;
        if(root==NULL)
            return;
        tmp.push_back(root);
        
        int s = 0;
        int num = 0;
        while(!tmp.empty()){
            s =tmp.size();
            num = 1;
            while(num<=s){
                tmp[0]->next = (num==s)?NULL:tmp[1];
                if(tmp[0]->left!=NULL)
                    tmp.push_back(tmp[0]->left);
                if(tmp[0]->right!=NULL)
                    tmp.push_back(tmp[0]->right);
                tmp.erase(tmp.begin());
                num++;
            }
        }
    }
};
