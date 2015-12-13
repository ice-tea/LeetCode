class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        //vector<vector<int>> res;
        vector<int> tmp;
        MyCombine(n,k,1,tmp);
        return res;
    }
    void MyCombine(int n, int k, int pos, vector<int> &tmp){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<=n;i++){
            tmp.push_back(i);
	    //cation not pos+1
	    // i+1 for the following pick
            MyCombine(n,k,i+1,tmp);
            tmp.pop_back();
        }
    }
};
