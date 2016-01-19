class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        int s=nums.size();
        for(int i=0;i<s;i++){
            n = n^nums[i];
        }
        return n;
    }
};
