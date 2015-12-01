class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxNums;
        vector<int> minNums;
        maxNums.push_back(nums[0]);
        minNums.push_back(nums[0]);
        int maxP = nums[0];
        int current;
        for(int i=1;i<nums.size();++i){
            current = max(maxNums[i-1]*nums[i],max(minNums[i-1]*nums[i],nums[i]));
            maxP=max(current,maxP);
            maxNums.push_back(current);
            minNums.push_back(min(minNums[i-1]*nums[i],min(maxNums[i-1]*nums[i],nums[i])));
        }
        return maxP;
    }
};
