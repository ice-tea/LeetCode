class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1=word1.size()+1;
        int s2=word2.size()+1;
        
        int* dp = new int[s1*s2];
        
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
                if(i==0)
                    dp[i*s2+j] = j;
                else if(j==0)
                    dp[i*s2+j] = i;
                else if(word1[i-1]==word2[j-1])
                    dp[i*s2+j] = dp[(i-1)*s2+j-1];
                else
                    dp[i*s2+j] = 1+ min(dp[(i-1)*s2+j-1],min(dp[(i-1)*s2+j],dp[i*s2+j-1]));
            }
        }
        
        return dp[s1*s2-1];
    }
};
