class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        MySearch(nums, tmp, res);
        return res;
    }
    void MySearch(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res){
        if(nums.size()==0){
            res.push_back(tmp);
            return;
        }
        int t = 0;
        for(int i=0;i<nums.size();++i){
            t = nums[i];
            tmp.push_back(t);
            nums.erase(nums.begin()+i);
            MySearch(nums,tmp,res);
            nums.insert(nums.begin()+i, t);
            tmp.pop_back();
        }
    }
};
