class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        string s2 = s;
        vector<string> res;
        if(s.size()<1)
            return res;
        for(int i=0;i<s.size()-1;++i){
            if(s[i]=='+' && s[i+1]=='+')
                res.push_back(getFlip(s,i));
        }
        return res;
    }
    inline string getFlip(string s,int pos){
        s[pos]='-';
        s[pos+1]='-';
        return s;
    }
};
