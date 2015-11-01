#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)  {
		int last = s.length();
		cout<<last<<endl;
		while(last>=0){
			if(s[--last]!=' ')
				break;
		}
		cout<<last<<endl;
		int lastSpace = 0;
		int i=0;
		while(i<=last){
			if(s[i++] == ' ')
				lastSpace = i;
		}
		return last-lastSpace+1;
    }
	int l(string s){
		int n=s.length()-1;
		    int len=0;
		    while(s[n]==' '){
		        n--;
		    }
		    for(int i=n;i>=0;i--){
		        if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
		            len++;
		        else break;
		    }
		    return len;
	}
};


int main(){

	Solution s;
	cout<<s.lengthOfLastWord("Hello World  ");
}