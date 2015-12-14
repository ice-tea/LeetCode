class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> MyMap1;
        map<string,char> MyMap2;
        int pos1=0,pos2=-1;
        string s;
        bool find = true;
        int i = 0;
        for(i=0;i<pattern.size()&&find;++i){
            pos1 = pos2+1;
            pos2 = str.find(' ', pos1);
            find = (pos2!=-1);
            if(!find)
                pos2 = str.size();
            s=str.substr(pos1,pos2-pos1);
            //cout<<"s = "<<s<<endl;
            if(MyMap1.find(pattern[i])!=MyMap1.end()){
                if(MyMap1[pattern[i]]!=s)
                    return false;
            }
            else
                MyMap1[pattern[i]]=s;
            if(MyMap2.find(s)!=MyMap2.end()){
                if(MyMap2[s] != pattern[i])
                    return false;
            }
            else
                MyMap2[s] = pattern[i];
        }
        return (pos2==str.size() && i == pattern.size());
    }
};
