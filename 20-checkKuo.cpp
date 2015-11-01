#include <stack>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
		char c;
		for(int i=0;i<s.size();++i){
			c = s[i];
			if(c!='('&&c!=')'&&c!='['&&c!=']'&&c!='{'&&c!='}')
				return false;
			if(c=='('||c=='['||c=='{'){
				st.push(c);
				continue;
			}
			else if(c==')'){
				if(st.size()==0||st.top()!='(')
					return false;
			}
			else if(c==']'){
				if(st.size()==0||st.top()!='[')
					return false;
			}
			else{
				if(st.size()==0||st.top()!='{')
					return false;
			}
			st.pop();
		}
		return st.size()==0;
    }
};

int main(){
	Solution s;
	if(s.isValid("()"))
		printf("yes!\n");
	else
		printf("no!\n");
}