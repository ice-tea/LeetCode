class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        MySearch(candidates,target,res,tmp,0);
        return res;
    }
    void MySearch(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> &tmp, int pos){
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        if(target<0){
            return;
        }
        int num = 0;
        for(int i=pos; i<candidates.size(); i+=num){
            num = 1;
            while(candidates[i+num] == candidates[i+num-1]){
                num++;
            }
            tmp.push_back(candidates[i]);
            MySearch(candidates,target-candidates[i],res,tmp,i+1);
            tmp.pop_back();
        }
    }
};
