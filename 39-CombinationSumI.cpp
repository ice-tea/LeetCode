class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        for(int i=pos; i<candidates.size(); i++){
            tmp.push_back(candidates[i]);
            MySearch(candidates,target-candidates[i],res,tmp,i);
            tmp.pop_back();
        }
    }
    /*
        vector<vector<int>> res;
        vector<int> tmp;
        combHelp(candidates,0,res,target,tmp);
        return res;
    }
    void combHelp(vector<int>& candidates, int pos, vector<vector<int>>& res, int target, vector<int> tmp){
        if(pos>=candidates.size() || target<0)
            return;
        if(target==0){
            res.push_back(tmp);
            return;
        }

        int num = candidates[pos];
        combHelp(candidates,pos+1,res,target,tmp);
        tmp.push_back(num);
        combHelp(candidates,pos+1,res,target-num,tmp);
    }
    */
};
