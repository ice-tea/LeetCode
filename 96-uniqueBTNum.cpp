class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        int tmp;
        int s;
        for(int i=2;i<=n;++i){
            tmp =0;
            s = res.size();
            for(int j=0;j<s;++j){
                tmp+= res[j]*res[s-1-j];
            }
            res.push_back(tmp);
        }
        return res[n];
    }
};
