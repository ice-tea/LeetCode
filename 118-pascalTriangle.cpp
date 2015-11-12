class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tmp;
        tmp.push_back(1);
        vector<vector<int>> res;
        if(numRows<1)
            return res;
            
        res.push_back(tmp);
        for(int i=1; i<numRows; i++){
            for(int j=tmp.size()-1;j>=0;j--){
                tmp[j] = tmp[j-1]+tmp[j];
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};
