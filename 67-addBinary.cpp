#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int s1=a.size();
		int s2=b.size();
		if(s1==0)
			return b;
		if(s2==0)
			return a;
		
		int l=(s1>s2)?s1:s2;
        string s(l+1,'0');
		int i=s1-1,j=s2-1,k=l;
		char tmp = '0';
		int t=0;
		while(i>=0 && j>=0){
			t = tmp - '0' + a[i--]-'0' + b[j--] -'0';
			s[k--] = t%2 +'0';
			tmp = '0' + t/2;
		}
		while(i>=0){
			t = tmp - '0' + a[i--]-'0';
			s[k--] = t%2 +'0';
			tmp = '0' + t/2;
		}
		while(j>=0){
			t = tmp - '0' + b[j--]-'0';
			s[k--] = t%2 +'0';
			tmp = '0' + t/2;
		}
		if(k>=0){
			t = tmp - '0';
			s[k--] = t%2 + '0';
		}
		return (s[0]!='0')?s:s.substr(1);
    }
	string addBinary2(string a, string b) {
	                string ret = "";
	                int carry = 0;
	                for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
	                        int m = (i >= 0 && a[i] == '1');
	                        int n = (j >= 0 && b[j] == '1');
	                        ret = to_string((m + n + carry) & 0x1) + ret;
	                        carry = (m + n + carry) >> 1;
	                }
	                return carry ? '1' + ret : ret;
	        }
};

int main(){
	
	Solution s;
	cout<< s.addBinary("11", "100");
	return 0;
}