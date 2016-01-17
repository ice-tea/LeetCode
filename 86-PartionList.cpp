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
    ListNode* partition(ListNode* head, int x) {
        if(head ==NULL)
            return head;
        ListNode* tmp = head;
        
        ListNode* biggerHead =new ListNode(1);
        ListNode* biggerTail =biggerHead;
        ListNode* smallerHead =new ListNode(0);
        ListNode* smallerTail =smallerHead;
        
        ListNode* cur = head;
        while(cur!= NULL){
            tmp = cur->next;
            cur->next = NULL;
            if(cur->val >= x){
                biggerTail -> next = cur;
                biggerTail = biggerTail->next;
            }
            else{
                smallerTail -> next = cur;
                smallerTail = smallerTail->next;
            }
            cur = tmp;
        }
        smallerTail -> next = biggerHead->next;
        return smallerHead->next;
    }
};
