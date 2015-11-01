#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int s = nums.size();
		if(s==0)
			return 0;
		int i = 1, t = 1,tmp=0;
		//vector<int>::iterator i = nums.begin();
		//vector<int>::iterator temp;
		//int numbers =0;
		while(t<s){
			if(nums[i]==nums[i-1]){
				tmp = nums[i];
				nums.erase(nums.begin()+i);
				//nums.push_back(tmp);
			}
			else{
				++i;
			}
			++t;
		}
        return i;
    }
	
	int removeDuplicates2(vector<int>& nums) {
	    int pos = 0;

	    for (int i = 0; i < nums.size(); ++i) {
	        if (i == 0 || nums[i] != nums[pos - 1])
	            nums[pos++] = nums[i];
	    }

	    return pos;
	}
	int removeDuplicates22(vector<int>& nums) {
	        int s = nums.size();
			if(s<=2)
				return s;
			int i = 2, t = 2,tmp=0;
			//vector<int>::iterator i = nums.begin();
			//vector<int>::iterator temp;
			//int numbers =0;
			while(t<s){
				if(nums[i]==nums[i-1] && nums[i]==nums[i-2]){
					nums.erase(nums.begin()+i);
					//nums.push_back(tmp);
				}
				else{
					++i;
				}
				++t;
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
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	print(a,4);
	
	Solution s;
	int t = s.removeDuplicates(a);
	print(a,t);
	return 0;
}