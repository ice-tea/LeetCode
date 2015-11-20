class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s==0)
            return 0;
        int a = 0;
        int b = nums[0];
        int tmp = 0;
        for(int i=1;i<s;i++){
            tmp = max(b,a+nums[i]);
            a = b;
            b = tmp;
        }
        return b;
    }
};
