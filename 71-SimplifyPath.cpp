class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int pos1=0,pos2=0;
        string subS;
        bool find = true;
        int i = 0;
        while(pos2!=path.size() && pos2!=path.size()-1 && find){
            pos1 = pos2+1;
            pos2 = path.find('/', pos1);
            find = (pos2!=-1);
            if(!find)
                pos2 = path.size();
            subS=path.substr(pos1,pos2-pos1);
            cout<<"subS = "<<subS<<endl;
            if(subS=="." || subS == "")
                continue;
            else if(subS==".."){
                if( !s.empty())
                    s.pop();
            }
            else
                s.push(subS);
        }
        string res = "";
        if(s.empty())
            return "/";
        while(!s.empty()){
            res = "/" + s.top() + res;
            s.pop();
        }
        return res;
    }
};
