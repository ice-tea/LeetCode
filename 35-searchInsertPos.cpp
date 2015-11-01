class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int tmp = (low+high)/2;
        while(low<=high){
            tmp = (low+high)/2;
            if(nums[tmp] == target)
                return tmp;
            else if(nums[tmp] > target)
                high = tmp-1;
            else
                low = tmp+1;
        }
        if(nums[tmp]>=target)
            return tmp;
        return tmp+1;
    }
};
