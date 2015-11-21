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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1 = 0;
        int s2 = 0;
        ListNode * tmp1 = headA;
        while(tmp1!=NULL){
            tmp1 = tmp1->next;
            s1++;
        }
        ListNode * tmp2 = headB;
        while(tmp2!=NULL){
            tmp2 = tmp2 ->next;
            s2++;
        }
        tmp1 = headA;
        tmp2 = headB;
        while(s2>s1){
            tmp2 = tmp2->next;
            s2--;
        }
        while(s1>s2){
            tmp1 = tmp1->next;
            s1--;
        }
        while(tmp1!=tmp2){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return tmp1;
    }
};
