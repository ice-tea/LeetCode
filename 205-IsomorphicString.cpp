class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> posA,posB;
        int a,b;
        
        for(int i; i<s.size();i++){
            a = posA[s[i]];
            b = posB[t[i]];
            posA[s[i]] =i+1;
            posB[t[i]] =i+1;
            if (a!=b)
                return false;
        }
        return true;
    }
};
