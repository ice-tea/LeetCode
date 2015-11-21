class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> res(s,1);
        int tmp;
        for(int i=1;i<s;++i){
            res[i] = res[i-1]*nums[i-1];
        }
        tmp = nums.back();
        for(int i=s-2;i>=0;--i){
            res[i] = res[i]*tmp;
            tmp = tmp*nums[i];
        }
        return res;
    }
};
