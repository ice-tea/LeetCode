class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0)
            return res;
        res.push_back(1);
        int s;
        int tmp=1;
        for(int i=0;i<n-1;i++){
            tmp*=2;
            s = res.size();
            for(int j=s-1;j>=0;--j){
                res.push_back(res[j]+tmp);
            }
        }
        return res;
    }
};
