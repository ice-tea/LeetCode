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
   ListNode* partition(ListNode* head, int x) {
       if(head ==NULL)
           return head;
       ListNode* tmp = head;
       //ListNode* tail = head;
       ListNode* biggerHead =NULL;
       ListNode* biggerTail =NULL;
       bool found =false;
       while(tmp->next != NULL){
           if(tmp->next->val > x){
               biggerHead = tmp->next;
               biggerTail = tmp->next;
               tmp->next = tmp->next->next;
               tmp = tmp->next;
               found = true;
               break;
           }
           else{
               tmp = tmp->next;
           }
       }
       if(!found)
           return head;
       while(tmp->next != NULL){
           if(tmp->next->val > x){
               biggerTail->next = tmp->next;
               tmp->next = tmp->next->next;
           }
           tmp = tmp->next;
       }
       biggerTail->next = NULL;
       tmp->next = biggerHead;
       return head;
   }
};

int main(){
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
	ListNode* a3 = new ListNode(3);
    a1->next = a2;
	a2->next = a3;
    
    Solution s;
 
    print(a1);
    print(s.partition(b, 2));
}
