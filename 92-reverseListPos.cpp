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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* mp = newHead;
        ListNode* np = newHead;
        while(--m>0){
            mp=mp->next;
        }
        while(n-->0){
            np=np->next;
        }
        ListNode* nextHead = np->next;
        ListNode* cur = mp->next;
        mp->next = nextHead;
        ListNode* tmp;
        while(cur!=nextHead){
            tmp = cur->next;
            cur->next = mp->next;
            mp->next = cur;
            cur = tmp;
        }
        return newHead->next;
    }
};
