class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
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
