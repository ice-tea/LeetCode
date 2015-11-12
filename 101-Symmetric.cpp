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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSym(root->left,root->right);
    }
    bool isSym(TreeNode* l, TreeNode* r){
        if(l==NULL)
            return r==NULL;
        if(r==NULL)
            return l==NULL;
        if(l->val!=r->val)
            return false;
        return isSym(l->left,r->right)&&isSym(l->right,r->left);
    }
};

bool isSymmetric(TreeNode *root) {  
2:       if(root == NULL) return true;  
3:       vector&lt;TreeNode*&gt; visitQueue;  
4:       visitQueue.push_back(root);  
5:       int curLevel=1;            
6:       while(curLevel &gt;0)  
7:       {  
8:            int i=0;  
9:            while(i&lt;curLevel)  
10:            {  
11:                 TreeNode* p = visitQueue[i];  
12:                 i++;  
13:                 if(p==NULL) continue;  
14:                 visitQueue.push_back(p-&gt;left);  
15:                 visitQueue.push_back(p-&gt;right);  
16:            }  
17:            int start = 0, end = curLevel-1;  
18:            while(start&lt; end)   
19:            {   
20:                 TreeNode *pl = visitQueue[start];   
21:                 TreeNode *pr = visitQueue[end];   
22:                 int l = pl== NULL? -1:pl-&gt;val;   
23:                 int r = pr== NULL? -1: pr-&gt;val;   
24:                 if(l!=r)   
25:                      return false;   
26:                 start++;   
27:                 end--;   
28:            }   
29:            visitQueue.erase(visitQueue.begin(), visitQueue.begin() + curLevel);                 
30:            curLevel = visitQueue.size();   
31:       }   
32:       return true;   
33:  }  
