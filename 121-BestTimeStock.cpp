class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        for(int i=prices.size()-1;i>0;--i){
            prices[i]-=prices[i-1];
        }
        prices[0]=0;
        vector<int> currentNums;
        vector<int> maxNums;
        currentNums.push_back(prices[0]);
        maxNums.push_back(prices[0]);
       int maxN=prices[0];
       int tmp;
       for(int i=1;i<prices.size();++i){
           tmp = max(prices[i],currentNums[i-1]+prices[i]);
           currentNums.push_back(tmp);
           tmp = max(tmp,maxNums[i-1]);
           maxNums.push_back(tmp);
            maxN = max(tmp,maxN);
       }
       return maxN;
    }
};
