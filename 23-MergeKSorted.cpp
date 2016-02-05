/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    class mycomp//construct
    {
        /*
        bool operator()(const pair<ListNode*,int>& a,const pair<ListNode*,int>& b)
        {
            return (a.first->val >b.first->val);
        }
        */
        public:
        bool operator () (const ListNode* a,const ListNode* b) const
        {
            return (a->val) >(b->val);
        }
    };
    
    /*
    static bool comp(const ListNode* & a,const ListNode* & b){
        return (a->val) >(b->val);
    }
    
    template<typename T> 
    static bool com(T& a, T& b) {
        return a->val > b->val;
    }
    */
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        
        if(lists.size()==0)
            return NULL;
        //priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,comp> firsts;
        priority_queue<ListNode*,vector<ListNode*>,mycomp> firsts;
        //priority_queue<ListNode*> firsts;
        for(int i=0;i<lists.size();++i){
            if(lists[i]!=NULL)
                firsts.push(lists[i]);
        }
        
        ListNode* cur = dummy;
        ListNode* tmp;
        
        while(firsts.size()>0){
            tmp = firsts.top();
            firsts.pop();
            if(tmp->next!=NULL){
                firsts.push(tmp->next);
            }
            
            tmp->next = NULL;
            cur->next = tmp;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
