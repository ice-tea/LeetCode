#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1 = haystack.length();
		int s2 = needle.length();
		if(s2==0)
			return 0;
		if(s2 > s1)
			return -1;
		int i=0,j=0;
		for(i=0,j=0; i<s1; ++i){
			
			while(haystack[i] == needle[j] && j<s2 && i<s1){
				cout<<haystack[i] <<"\t"<< needle[j]<<endl;
				++i;
				++j;
			}
			if(j==s2){
				return i-j;
			}
			i -= j;
			j = 0;
			cout<<i<<"\t"<<j<<endl;
		}
		return -1;
    }
    int strStr2(string haystack, string needle) {
        int s1 = haystack.length();
		int s2 = needle.length();
		if(s2==0)
			return 0;
		if(s2 > s1)
			return -1;
		int i=0,j=0;
		while(i<s1){
			if(haystack[i] == needle[j]){
				if(j==s2-1){
					break;
				}
				else{
					cout<<haystack[i] <<"\t"<< needle[j]<<endl;
					++j;
					++i;
				}
			}
			else{
				if(j == 0){
					++i;
				}
				else{
					i = i+1-j;
					j = 0;
				}
			}
		}
		return (i==s1)?-1:(i-j);
    }
	int strStr4(string haystack, string needle) {
	        int sz_haystack = haystack.size();
	        int sz_needle = needle.size();
	        for (int i = 0; i+sz_needle-1 < sz_haystack;)
	        {
	            if (needle == haystack.substr(i, sz_needle))
	                return i;
	            else
	            {
	                int step = sz_needle;
	                for (int j = 0; j <= sz_needle-2; j++)
	                {
	                    if (haystack[i+sz_needle-1] == needle[j])
	                        step = sz_needle-1-j;
	                }
	                i = i+step;
	            }
	        }
	        return -1;
	    }
	
};



int main(){
	Solution s;
	int t = s.strStr2("aaaab", "aab");
	cout<<t<<endl;
	return 0;
}