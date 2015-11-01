#include<iostream>
#include<string>
#include<vector>
#include <stdio.h>  
#include <math.h>

class Solution {
public:
    std::string getPermutation(int n, int k) {
		std::vector<int> nums;
		for(int i=1;i<=n;++i){
			nums.push_back(i);
		}
		
		int num =1,_n = n, _k=k, tmp=0;
		std::string res = "";
		char c;
		while(_n-->1){
			num*=_n;
			//--_n;
		}
		//std::cout<<num<<std::endl;
		while(n>=1){
			//std::cout<<"in  n=="<<n<<"  -K "<<_k<<"    :";
			
			tmp = ceil(_k*1.0/num)-1;
			c = '0' + nums[tmp];
			nums.erase(nums.begin()+tmp);
			res += c;
			_k = (_k%num==0)?num:_k%num;
			//std::cout<<tmp;
			if(n==1)
				break;
			else
				num/=--n;
			//std::cout<<"   "<<num<<std::endl;
		}
		
        return res;
    }
};

int main(){
	Solution s;
	std::cout<<s.getPermutation(3,6)<<std::endl;
	return 0;
}