class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        dfs(nums,tmp,visited,res);
        
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& tmp, vector<bool>& v,vector<vector<int>>& res){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!v[i]){
                v[i]=true;
                tmp.push_back(nums[i]);
                dfs(nums,tmp,v,res);
                v[i]=false;
                tmp.pop_back();
                while(i<nums.size() && nums[i]==nums[i+1])
                    i++;
            }
        }
    }
};
