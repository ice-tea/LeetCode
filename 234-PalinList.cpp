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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* tmp = head;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        while(fast!=NULL){
            tmp = fast;
            fast = fast->next;
            tmp ->next = slow->next;
            slow->next = tmp;
        }
        
        fast = slow->next;
        while(fast!=NULL){
            if(head->val != fast->val)
                return false;
            fast = fast->next;
            head = head->next;
        }
        return true;
    }
};

