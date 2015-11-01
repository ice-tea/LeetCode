#include<iostream>
using namespace std;

class Solution {
public:    
	//not O(n) but efficient enough
	string longestPalindrome(string s) {
		int size = s.length();
		if(size==1)
			return s;
		int j = 0, max = 0,maxP=0;
		for(int i=1;i<size;++i){
			if(s[i]==s[i-1]){
				j = 1;
				while(i-j-1>=0 && i+j<size && s[i-j-1] == s[i+j]){
					j++;
				}
				if(j*2>max){
					max = j*2;
					maxP = i;
				}
			}
			j = 1;
			while(i-j>=0 && i+j<size &&s[i-j] == s[i+j]){
				j++;
			}
			if(j*2-1>max){
				max = j*2-1;
				maxP = i;
			}
		}		
		return s.substr(maxP-max/2,max);
	}
	//Manacher algorithm O(n)
	//http://blog.csdn.net/ggggiqnypgjg/article/details/6645824
	string longestPalindrome2(string str) {
	    int len=str.length();
	    if(len<=1)return str;
	    string str1=str;
	    reverse(str1.begin(),str1.end());
	    if(str1==str)
	        return str;
	    string s;
	    s += "$#";
	    for(int i = 0; i < len; i++){
	        s += str[i];
	        s += "#";
	    }
	    s +="$";
	    int n=s.size();
	    int mx=0,Maxl=0,id=0;
	    int *p = new int[n];
	    memset(p,0,sizeof(p));
	    for(int i=1;i<n-1;i++){
	        p[i]=mx>i?min(mx-i,p[2*id-i]):1;
	        while(s[i-p[i]]==s[i+p[i]])
	            p[i]++;
	        if(p[i]>mx-i){
	            mx = p[i]+i;
	            id=i;
	        }
	        Maxl=max(Maxl,p[i]);
	    }
	    int mid=0;
	    for(int i=0;i<n;i++){
	        if(p[i]==Maxl)
	            mid=i;
	    }
	    int size=Maxl-1;
	    delete []p;
	    if(mid%2==0)
	        return str.substr(mid/2-size/2-1,size);
	    else
	        return str.substr((mid-size-1)/2,size);
	}
};



int main(){
	Solution s;
	string sub = s.longestPalindrome("aaaab");
	cout<<sub<<endl;
	return 0;
}