class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int s=0;
        if ((s = strs.size())==0)
            return "";
        if(s==1)
            return strs[0];
        bool stop = false;
        string res="";
        for(int i=0;i<strs[0].size()&&!stop;++i){
            for(int j=1;j<s;++j){
                if(strs[j][i]!=strs[0][i]){
                    stop = true;
                    break;
                }
            }
            if(!stop)
                res+=strs[0][i];
        }
        return res;
    }
};
