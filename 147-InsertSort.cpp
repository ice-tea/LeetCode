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
    ListNode* insertionSortList(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode * pre = dummy;
        ListNode * tmp = head;
        ListNode * minPre = head;
        while(pre->next){
            tmp = pre->next;
            minPre = pre;
            while(tmp->next){
                if(minPre->next->val > tmp->next->val){
                    minPre = tmp;
                }
                tmp = tmp->next;
            }
            tmp = minPre->next;
            minPre->next = minPre->next->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = pre->next;
        }
        return dummy->next;
    }
};
