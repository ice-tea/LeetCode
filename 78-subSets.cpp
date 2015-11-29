class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        vector<int> empty;
        res.push_back(empty);
        sort(nums.begin(),nums.end());
        int s=nums.size();
        int i=0;
        int len = 0;
        while(i<s){
            len = res.size();
            for(int j=0;j<len;++j){
                res.push_back(res[j]);
                res[len+j].push_back(nums[i]);
            }
            i++;
        }
        return res;
    }
};
