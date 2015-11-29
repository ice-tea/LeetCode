class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        vector<int> empty;
        res.push_back(empty);
        sort(nums.begin(),nums.end());
        int s=nums.size();
        int i=0;
        int same = 0;
        int len = 0;
        while(i<s){
            same = 0;
            len = res.size();
            do{
                for(int j=0;j<len;++j){
                    res.push_back(res[len*same+j]);
                    res[len+len*same+j].push_back(nums[i]);
                }
                i++;
                same++;
            }while(i>0 && i<s && nums[i]==nums[i-1]);
        }
        return res;
    }
};
