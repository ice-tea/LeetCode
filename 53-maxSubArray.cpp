class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s= nums.size();
        int glo = nums[s-1];
        int cur = nums[s-1];
        int tmp;

        for(int i=s-2;i>=0;--i){
            tmp = max(nums[i], nums[i]+cur);
            glo = max(glo,tmp);
            cur = tmp;
        }
        return glo;
    }
};
