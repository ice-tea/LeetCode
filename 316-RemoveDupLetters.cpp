class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        set<char> cons;
        for(int i=0;i<s.size();++i){
            if(st.empty()){
                cons.insert(s[i]);
                st.push(s[i]);
                continue;
            }
            if(cons.find(s[i]) != cons.end()){
                continue;
            }
            while(!st.empty() && s[i]<st.top()){
                if(s.find(st.top(),i+1)==-1){
                    break;
                }
                else{
                    cons.erase(st.top());
                    st.pop();
                }
            }
            cons.insert(s[i]);
            st.push(s[i]);
        }
        string res;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
