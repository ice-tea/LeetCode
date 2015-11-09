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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL ||head->next==NULL)
            return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode* nh = newhead;
        ListNode* tmp = head;
        while(nh->next!=NULL && nh->next->next!=NULL){
            tmp = nh->next;
            nh->next = nh->next->next;
            tmp->next = nh->next->next;
            nh->next->next = tmp;
            nh = tmp;
        }
        return newhead->next;
    }
};
