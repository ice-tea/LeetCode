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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head ==NULL ||head->next==NULL)
            return head;
            
        ListNode* tmp = head;
        while(tmp->next!=NULL){
            if(tmp->val == tmp->next->val){
                tmp->next= tmp->next->next;
            }
            else
                tmp = tmp->next;
        }
        return head;
    }
};
