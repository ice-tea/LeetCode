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
		if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		
		ListNode *c1 = l1;
		ListNode *c2 = l2;
		ListNode *nc1;
		ListNode *nc2;
		while(c1!=NULL &&c2!=NULL){
			if(c1->val>c2->val){
				while(c2->next!=NULL&&c2->next->val<=c1->val){
					c2 = c2->next;
				}
				nc2 = c2->next;
				c2->next=c1;
				c2=nc2;
			}
			else{
				while(c1->next!=NULL&&c1->next->val<=c2->val){
					c1 = c1->next;
				}
				nc1 = c1->next;
				c1->next=c2;
				c1=nc1;
			}
		}
		return (l1->val>l2->val)?l2:l1;
	}
};


int main(){
    ListNode* a1 = new ListNode(-9);
    ListNode* a2 = new ListNode(-7);
	ListNode* a3 = new ListNode(-3);
    a1->next = a2;
	a2->next = a3;
    
	ListNode* b1 = new ListNode(-7);
    ListNode* b2 = new ListNode(-7);
    ListNode* b3 = new ListNode(-6);
    b1->next = b2;
	b2->next = b3;
    Solution s;
 
    print(a1);
    print(b1);
    print(s.mergeTwoLists(b1, a1));
}