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
	ListNode* rotateRight(ListNode* head, int k) {
		if(head==NULL ||head->next==NULL)
			return head;
		
		ListNode* tmp=head;
		ListNode* tail = head;
		
		int len = 0;
		while(tail!=NULL){
			tail = tail->next;
			len++;
		}
		k = k%len;
		tail = head;
		
		while(k-->0 && tail!=NULL){
			tail = tail->next;
		}
		while(tail->next!=NULL){
			tail = tail->next;
			tmp = tmp->next;
		}
		tail->next = head;
		tail = tmp;
		tmp = tmp->next;
		tail->next = NULL;
		return tmp;
	}
};

int main(){
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
    a1->next = a2;
	a2->next = a3;
    
    Solution s;
 
    //print(a1);
    print(s.rotateRight(a1, 4));
}