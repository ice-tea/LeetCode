class Solution {
private:
    int leftMax;
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        set<string> setRes;
        
        leftMax=INT_MIN;
        string tmp="";
        dfs(s,0,tmp,0,0,setRes);
        //cout<<leftMax<<endl;
        
        vector<string> res(setRes.size());
        copy(setRes.begin(),setRes.end(),res.begin());
        return res;
    }
    void dfs(string s, int pos, string tmp, int leftMost, int leftUnmatch, set<string>& res){
        if(pos>=s.size()){
            if(leftUnmatch == 0){
                if(leftMost>leftMax){
                    leftMax = leftMost;
                }
                if(leftMax == leftMost){
                    res.insert(tmp);
                    cout<<tmp<<endl;
                }
            }
            return;
        }
        if(s[pos] == '('){
            dfs(s,pos+1,tmp+'(', leftMost+1,leftUnmatch+1,res);
            dfs(s,pos+1,tmp, leftMost,leftUnmatch,res);
        }
        else if(s[pos] == ')'){
            if(leftUnmatch > 0){
                dfs(s,pos+1,tmp+')', leftMost,leftUnmatch-1,res);
            }
            dfs(s,pos+1,tmp, leftMost,leftUnmatch,res);
        }
        else
            dfs(s,pos+1,tmp+s[pos], leftMost,leftUnmatch,res);
    }
};
// not tmp+= .....
