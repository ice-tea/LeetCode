#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int s = nums.size();
		int i = 0, t = 0;
		//vector<int>::iterator i = nums.begin();
		//vector<int>::iterator temp;
		//int numbers =0;
		while(t<s){
			if(nums[i]==0){
				nums.erase(nums.begin()+i);
				nums.push_back(0);
			}
			else{
				++i;
			}
			++t;
		}
        return;
    }
};

void print(vector<int> v){
	for(vector<int>::iterator i=v.begin();i!=v.end();++i){
		cout<<*i<<"\t";
	}
	cout<<endl;
}

int main(){
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(1);
	//nums.push_back(3);
	//nums.push_back(12);
	Solution s;
	s.moveZeroes(nums);
	print(nums);
}


