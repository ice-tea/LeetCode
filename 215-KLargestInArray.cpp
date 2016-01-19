class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> res;
        int i=0;
        while(i<k){
            res.push_back(nums[i++]);
        }
        sort(res.begin(),res.end());
        int j=0;
        while(i<nums.size()){
            if(nums[i] > res[0]){
                for(j=1; j<k; ++j){
                    if(nums[i] > res[j])
                        res[j-1] = res[j];
                    else
                        break;
                }
                res[j-1] = nums[i];
            }
            ++i;
        }
        return res[0];
    }
};
