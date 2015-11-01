#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	
	int removeElement(vector<int>& nums, int val) {
		int s = nums.size();
		int i = 0, t = 0;
		//vector<int>::iterator i = nums.begin();
		//vector<int>::iterator temp;
		//int numbers =0;
		while(t<s){
			if(nums[i]==val){
				nums.erase(nums.begin()+i);
				nums.push_back(val);
			}
			else{
				++i;
			}
			++t;
		}
        return i;
    }

	int removeElement2(vector<int>& nums, int val) {
		int i=0;
		for (int j=0; j<nums.size(); j++){
			if (nums[j]!=val) nums[i++]=nums[j];
		}
		return i;
	}
};

void print(vector<int> nums, int size){
	for(int i=0;i<size;++i){
		cout<<nums[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	print(a,4);
	
	Solution s;
	int t = s.removeElement(a, 1);
	print(a,t);
	return 0;
}