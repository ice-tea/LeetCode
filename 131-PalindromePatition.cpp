class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> res;
        bfs(s,0,tmp,res);
        return res;
    }
    void bfs(string s, int pos, vector<string> tmp, vector<vector<string>>& res){
        if(pos==s.size()){
            res.push_back(tmp);
            return;
        }
        bool valid;
        for(int i=pos;i<s.size(); ++i){
            valid = true;
            for(int j=0;pos+j<=i-j && valid; ++j)
                if(s[pos+j] != s[i-j])
                    valid = false;
            if(valid){
                tmp.push_back(s.substr(pos,i-pos+1));
                bfs(s,i+1,tmp,res);
                tmp.pop_back();
            }
        }
    }
};
