#include<string>
#include <sstream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		bool minus = x<0;
		string str;
		ostringstream temp;
		temp<<x;
		str=temp.str();
		string res;
		if(minus){
			res.assign(str.rbegin(), --str.rend());
		}
		else{
			res.assign(str.rbegin(), str.rend());
		}
		//printf("%s",res.c_str());
		int digit = 0;
		int sum = 0;
		//convert str to int
		int i = 0;
		while(i<res.size()){
			digit = (int)(res[i++]-'0');  
			if(minus && sum>-((numeric_limits<int>::min()+digit)/10))  
				return 0;
			else if(!minus && sum>(numeric_limits<int>::max()-digit)/10)  
				return 0;
			sum = sum*10+digit;
		}
		return minus?-sum:sum;
    }
	int reverse2(int x) {
	        int re;
	        string s = to_string(x);
	        auto l = s.begin();
	        auto r = prev(s.end());
	        if(*l=='-')l++;
	        while(l<r){
	            char temp = *l;
	            *l = *r;
	            *r = temp;
	            l++;
	            r--;
	        }
	        try{
	          re =  stoi(s);
	        }catch(exception e){
	            re = 0;
	        }
	        return re;
	    }
};

int main(){
	Solution s;
	printf("%d",s.reverse2(-13432));
}