class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> CharCount;
        for(int i=0;i<s.size();++i){
            CharCount[s[i]]++;
        }
        int odds =0;
        for(auto c:CharCount){
            if(c.second%2 == 1)
                odds++;
            if(odds>1)
                break;
        }
        return (odds<=1);
    }
};
