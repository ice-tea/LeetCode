#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapping;  
	    vector<int> result;
 
	    for (int i = 0; i < nums.size(); i++) {
		    if (mapping.find(target - nums[i])!=mapping.end()) {
			    result.push_back(mapping[target - nums[i]]+1);
			    result.push_back(i+1);
    			break;
	    	}
	        else {
		    	mapping[nums[i]]=i; 
		    }
    	}
 
	    return result;
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
	vector <int> res = s.twoSum(nums, 5);
	print(res);
}