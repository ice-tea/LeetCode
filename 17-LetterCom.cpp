class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s="";
        vector<string> res;
        comHelp(digits,0,res,s);
        return res;
    }
    void comHelp(string digits, int pos, vector<string> &res, string s){
        if(pos == digits.size()){
            if(s.size()!=0)
                res.push_back(s);
            return;
        }
        int num = digits[pos]-'0';
        string cur = getString(num);
        for(int i=0;i<cur.size();++i){
            comHelp(digits, pos+1, res, s+cur[i]);
        }
    }
    string getString(int n){
        if(n==0||n==1)
            return "";
        if(n==2)
            return "abc";
        if(n==3)
            return "def";
        if(n==4)
            return "ghi";
        if(n==5)
            return "jkl";
        if(n==6)
            return "mno";
        if(n==7)
            return "pqrs";
        if(n==8)
            return "tuv";
        if(n==9)
            return "wxyz";
    }
};
