class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       vector<int> currentNums;
       vector<int> maxNums;
       currentNums.push_back(nums[0]);
       maxNums.push_back(nums[0]);
       int maxN=nums[0];
       int tmp;
       for(int i=1;i<nums.size();++i){
           tmp = max(nums[i],currentNums[i-1]+nums[i]);
           currentNums.push_back(tmp);
           tmp = max(tmp,maxNums[i-1]);
           maxNums.push_back(tmp);
            maxN = max(tmp,maxN);
       }
       return maxN;
    }
};
