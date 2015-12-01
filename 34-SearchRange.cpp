class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos1 = searchLess(nums,target);
        int pos2 = searchBig(nums,target);
        vector<int> res;
        bool noExist = (pos2-pos1)==1;
        res.push_back(noExist?-1:pos1+1);
        res.push_back(noExist?-1:pos2-1);
        return res;
    }
    int searchLess(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int tmp = (low+high)/2;
        while(low<=high){
            tmp = (low+high)/2;
            if(nums[tmp] < target)
                low = tmp+1;
            else
                high = tmp-1;
        }
        if(nums[tmp]<target)
            return tmp;
        return tmp-1;
    }
    int searchBig(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int tmp = (low+high)/2;
        while(low<=high){
            tmp = (low+high)/2;
            if(nums[tmp] > target)
                high = tmp-1;
            else
                low = tmp+1;
        }
        if(nums[tmp]>target)
            return tmp;
        return tmp+1;
    }
};
