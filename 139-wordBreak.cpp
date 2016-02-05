class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        string s2 = '$'+s;
        vector<bool> dp(len+1,false);
        
        dp[0] = true;
        for(int i=1;i<=len;++i){
            for(int j=0;j<i;++j){
                dp[i] = dp[j] && wordDict.find(s2.substr(j+1, i-j)) != wordDict.end();
                if(dp[i])
                    break;
            }
        }
        return dp[len];
    }
};
