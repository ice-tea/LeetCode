#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode * hd){
    while (hd!= NULL) {
        std::cout<<hd->val<<"   ";
        hd = hd->next;
    }
    std::cout<<std::endl;
    
}
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
	    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)
            return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        ListNode* result = l1;
        bool upper = false;
        int sum = 0;
        while(l1->next!=NULL && l2->next!=NULL){
            sum = l1->val + l2->val;
            sum += upper?1:0;
            upper = sum>=10;
            l1->val = upper?sum%10:sum;
            l2->val = l1->val;
            l1=l1->next;
            l2=l2->next;
        }
        sum = l1->val + l2->val;
        sum += upper?1:0;
        upper = sum>=10;
        l1->val = upper?sum%10:sum;
        l2->val = l1->val;
        if(l1->next==NULL&&l2->next==NULL){
            if(upper)
                l1->next = new ListNode(0);
            else
                return result;
        }
        l1->next = (l1->next==NULL)?l2->next:l1->next;
        l2->next = (l2->next==NULL)?l1->next:l2->next;
        l1=l1->next;
        l1->val += upper?1:0;
        while(l1->val==10){
            l1->val = 0;
            if(l1->next!=NULL){
                l1->next->val+=1;
                l1 = l1->next;
            }
            else{
                l1->next=new ListNode(1);
                break;
            }
        }
        return result;
    }
};

int main(){
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
    a1->next = a2;
	a2->next = a3;
    
 
    print(a1);
    
	Solution s;
    print(s.removeNthFromEnd(a1,3));
}