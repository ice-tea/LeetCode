class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<vector<int>> res;
        MySearch(k, n, res,tmp,1);
        return res;
    }
    void MySearch(int k, int n, vector<vector<int>>& res, vector<int> &tmp, int pos){
        if(n == 0 && tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        if(n<0 || tmp.size()>=k){
            return;
        }
        for(int i=pos; i<=9; i++){
            tmp.push_back(i);
            MySearch(k,n-i,res,tmp,i+1);
            tmp.pop_back();
        }
    }
};
