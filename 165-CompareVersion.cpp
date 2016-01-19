class Solution {
public:
    int compareVersion(string version1, string version2) {
        return compareRe(version1,version2);
    }
    int compareRe(string s1, string s2){
        int pos1 = s1.find('.');
        int pos2 = s2.find('.');
        
        string v1F = s1.substr(0,(pos1==-1)?s1.size():pos1);
        string v1A = (pos1==-1)?"":s1.substr(pos1+1);
        
        string v2F = s2.substr(0,(pos2==-1)?s2.size():pos2);
        string v2A = (pos2==-1)?"":s2.substr(pos2+1);
        cout<<v1F<<" "<<v1A<<endl;
        cout<<v2F<<" "<<v2A<<endl;
        int res = compare(v1F,v2F);
        if(res!=0)
            return res;
        //check After
        if(v1A=="" &&v2A == "")
            return 0;
        return compareRe(v1A, v2A);
    }
    int compare(string s1, string s2){
        int i=0;
        while(i<s1.size() && s1[i]=='0')
            i++;
        s1 = s1.substr(i);
        i = 0;
        while(i<s2.size() && s2[i]=='0')
            i++;
        s2 = s2.substr(i);
        cout<<s1<<" "<<s2;
        
        if(s1.size()!=s2.size())
            return (s1.size()>s2.size())?1:-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                return (s1[i]>s2[i])?1:-1;
        }
        return 0;
    }
};
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        if(version1 == version2)
        {
            return 0;
        }
        else
        {
            int v1 = 0, v2 = 0;
            while(v1 < version1.length() || v2 < version2.length())
            {
                string temp1 = "";
                string temp2 = "";
                while(version1[v1] != '.' && v1 < version1.length())
                {
                    temp1 +=version1[v1];
                    ++v1;
                }

                while(version2[v2] != '.' && v2 < version2.length())
                {
                    temp2 +=version2[v2];
                    ++v2;
                }

                if(temp1 == "") temp1 = "0";
                if(temp2 == "") temp2 = "0";

                if(stoi(temp1) != stoi(temp2))
                {
                    return stoi(temp1) > stoi(temp2) ? 1 : -1;
                }
                ++v1;
                ++v2;
            }
            return 0;
        }
    }
};
