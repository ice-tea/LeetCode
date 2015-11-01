#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
		if(x==1)
			return 1;
		if(x==-1)
			return (n%2==0)?1:-1;
	   if(n==0)
            return 1;
        if(n==1)
            return x;
        bool reverse =n<0;
		n = reverse?0-n:n;
        double result = 0;
       stack<int> s;
       int i = 1;
       while(n>1){
           if(n%2==1){
               s.push(i);
               i=1;
			   n--;
           }
		   else{
	           i++;
	           n/=2;
		   }
       }
	   s.push(i);
	   print(s);
	   
	   int t;
	   result=x;
	   while(!s.empty()){
		   t = s.top();
		   s.pop();
		   while(t-->1){
			   result*=result;
		   }
		   result*=x;
	   }
	   result/=x;
       return reverse?1/result:result;
    }
	
	//brillent
    double myPow(double x, int n)
       {
           bitset<32> bit(abs(n));
           double result = 1;
           for(int i = bit.size()-1; i >= 0; i--)
           {
               result*=result;
               if(bit[i] == 1)
                   result *=x;
           }
           return (n >= 0)?result : 1/result;
       }
	   
	void print(stack<int> s){
		while(!s.empty()){
			cout<<s.top()<<"  ";
			s.pop();
		}
		cout<<endl;
	}
};


int main(){
    Solution s;
	for(int i=0;i<11;i++){
		//cout<<s.myPow(-1,i)<<"  ";
	}
	cout<<s.myPow(-1.00000,2147483646)<<endl;
	cout<<s.myPow(-1,2147483647)<<endl;
	cout<<s.myPow(-1.00000,2147483648)<<endl;
	cout<<s.myPow(-1,2147483649)<<endl;
}