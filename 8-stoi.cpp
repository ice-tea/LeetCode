#include<string>
#include <limits>    
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int size = str.size();
		int minus = 0;
		int fu = 0;
		int current = 0;
		
		while(!isdigit(str[current])){
			if(fu==1&&!isdigit(str[current]))
				return 0;
			if(str[current]=='-'||str[current]=='+'){
				if(fu==1)
					return 0;
				fu = 1;
				if(str[current]=='-')
					minus = 1;
			}
			if(isalpha(str[current]))
				return 0;
			current++;
		}
		
		int sum = 0;
		int digit = 0;
		
		while(current < size){
			if(isdigit(str[current])){
				digit = (int)(str[current++]-'0');  
				if(minus && sum>-((numeric_limits<int>::min()+digit)/10))  
					return numeric_limits<int>::min();
				else if(!minus && sum>(numeric_limits<int>::max()-digit)/10)  
					return numeric_limits<int>::max();
				sum = sum*10+digit;
			}
			else
				break;
		}
		if(minus==1)
			return 0-sum;
		
        return sum;
    }
	
	int myAtoi2(string str) {
	    if(((str[0]-'0'<0)||(str[0]-'9'>0))&&(str[0]!='+')&&(str[0]!='-')&&(str[0]!=' '))
	    {
	        return 0;
	    }
	    int flag=1,index=0;
	    double answer=0;
	    while(str[index]==' ')
	    {
	        index++;
	    }
	    if(str[index]=='+')
	    {
	        flag=1;
	        index++;
	    }
	    else if(str[index]=='-')
	    {
	        flag=-1;
	        index++;
	    }
	    for(int i=index,s=str.length();i<s;i++)
	    {
	        if((str[i]>='0')&&(str[i]<='9'))
	        {
	            answer=(str[i]-'0')+answer*10;
	        }
	        else
	        {
	            break;
	        }
	    }
	    answer=answer*flag;
	    if(answer>2147483647)
	    {
	        return 2147483647;
	    }
	    else if(answer<-2147483648)
	    {
	        return -2147483648;
	    }
	    else
	    {
	        return answer;
	    }
	}
};


int main(){
	Solution s;
	printf("%d",s.myAtoi("+1"));
}