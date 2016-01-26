class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = nums.size();
        for(int i=1;i<s-1;++i){
            if(nums[i]>nums[i-1] && nums[i+1]<nums[i])
                return i;
        }
        if(nums[s-1]>nums[s-2])
            return s-1;
        return 0;
    }
};
