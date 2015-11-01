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
class Solution2 {
public:
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {  
        ListNode* result = new ListNode(-1);  
        ListNode* pre = result;  
        ListNode *pa = l1, *pb = l2;  
        int carry =0;  
        while(pa!=NULL || pb!=NULL)  
        {  
			int av = pa == NULL? 0:pa->val;  
			int bv = pb == NULL? 0:pb->val;   
            ListNode* node = new ListNode((av+bv+carry)%10);  
            carry = (av+bv+carry)/10;  
            pre->next = node;  
            pre = pre->next;  
			pa = pa==NULL? NULL:pa->next;  
			pb = pb==NULL? NULL:pb->next;    
        }            
        if(carry > 0)  
             pre->next = new ListNode(1);  
        pre = result->next;  
        delete result;  
        return pre;  
   }  
};

int main(){
    ListNode* a1 = new ListNode(9);
    ListNode* a2 = new ListNode(9);
	ListNode* a3 = new ListNode(9);
    a1->next = a2;
	a2->next = a3;
    
	ListNode* b = new ListNode(1);
    Solution s;
	Solution2 s2;
 
    print(a1);
    print(b);
	print(s2.addTwoNumbers(b, a1));
    print(s.addTwoNumbers(b, a1));
}