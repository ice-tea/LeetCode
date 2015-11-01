#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)  {
		int dig = digits.size() - 1;
		    while(dig >= 0){
		        if(digits[dig] < 9){
		            digits[dig]++; 
		            break;
		        }
		        digits[dig--] = 0;
		    }
		    if(dig == -1) digits.insert(digits.begin(), 1);
		    return digits;
    }
};

void print(vector<int> v){
	for(vector<int>::iterator i=v.begin();i!=v.end();++i){
		printf("%d  ",*i);
	}
	printf("\n");
}

int main(){
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(2);
	Solution s;
	vector <int> res = s.plusOne(nums);
	print(res);
}