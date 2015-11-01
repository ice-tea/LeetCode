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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head==NULL)
			return NULL;
		ListNode* preHelp = head;
		ListNode* pre = head;
		while(n>0&&preHelp!=NULL){
			preHelp = preHelp->next;
			n--;
		}
		if(preHelp==NULL){
			return head->next;
		}
		while(preHelp->next!=NULL){
			preHelp = preHelp->next;
			pre = pre->next;
		}
		pre->next=pre->next->next;
        return head;
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