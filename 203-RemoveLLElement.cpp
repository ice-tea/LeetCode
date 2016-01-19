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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        while(head!=NULL && head->val == val){
            head = head->next;
        }
        if (head == NULL)
            return NULL;
        ListNode* pre = head;
        while(pre->next !=NULL){
            if(pre->next->val == val)
                 pre->next = pre->next->next;
            else
                pre = pre->next;
        }
        return head;
    }
};
