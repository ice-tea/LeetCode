#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		int x = n, high = 1;
		if(x==0)
			return "0";
		if(x==1)
			return "1";
		while(x>0){
			x/=10;
			high*=10;
		}
		high/=10;
		cout<<high<<endl;
		int tmp=0, cur = 0, num=0;
		string s;
		while(high>0){
			tmp = (n/high)%10;
			if(tmp == cur){
				num ++;
			}
			else{
				if(cur!=0){
					s += num +'0';
					s += cur +'0';
				}
				cur = tmp;
				num = 1;
			}
			high/=10;
		}
		if(cur!=0){
			s += num +'0';
			s += cur +'0';
		}
        return s;
    }
	string countAndSay2(int n){
		if(n==1)
			return "1";
		else {
	    	string ans=countAndSay(n-1);
	    	string res;
	    	int i=0;
	    	while(i<ans.length()) {
				char c_start = ans[i];
	        	int j=i;
	        	int num = 0;
	        	while(ans[j]==c_start&&j<ans.length()) {
	            	j++;
	            	num++;
	        	}
	        	char temp = num+'0';
	        	res.push_back(temp);
	        	res.push_back(c_start);
	        	i=i+num;
			}
		return res;
		}	
	}
};

int main(){
	Solution s;
	cout<<s.countAndSay2(11)<<endl;
}