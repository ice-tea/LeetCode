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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        bool curDelete = false;
        ListNode* pre = dummy;
        while(pre->next !=NULL){
            if(pre->next->next !=NULL){
                if(pre->next->next->val ==pre->next->val){
                    curDelete = true;
                    pre->next = pre->next->next;
                }
                else{
                    if(curDelete){
                        pre->next = pre->next->next;
                        curDelete = false;
                    }
                    else{
                        pre = pre->next;
                    }
                }
            }
            else{
                if(curDelete){
                    pre->next = pre->next->next;
                }
                break;
            }
        }
        return dummy->next;
    }
};
