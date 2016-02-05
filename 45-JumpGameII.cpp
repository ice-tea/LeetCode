class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(nums.size()<=1)
            return 0;
        int step = 1;
        
        int curMax = 0;
        int next = nums[0];
        
        int i = 0;
        while(next<len-1 && i<len){
            while(i<=next){
                curMax = max(curMax, nums[i]+i);
                ++i;
            }
            //if(curMax == next)
              //  break;
            next = curMax;
            step++;
        }
        return step;
    }
};
