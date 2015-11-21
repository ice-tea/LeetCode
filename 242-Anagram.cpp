class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<s.size();++i){
            m1[s[i]]++;
        }
        for(int i=0;i<t.size();++i){
            m2[t[i]]++;
        }
        map<char,int>::iterator it;
        for(it=m1.begin();it!=m1.end();++it){
            if(m2[it->first]!=it->second)
                return false;
        }
        for(it=m2.begin();it!=m2.end();++it){
            if(m1[it->first]!=it->second)
                return false;
        }
        return true;
    }
};
/*
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    // For string s to add each bit.
    // For string t to minus each bit.
    int items[26];
    memset(items, 0, sizeof(items));
    for (int i=0; i < s.length(); ++i) {
        int index1 = s[i] - 'a';
        int index2 = t[i] - 'a';
        ++ items[index1];
        -- items[index2];
    }

    // If all zero, then it is an anagram
    bool isA = true;
    for (int i=0; i<26; ++i) {
        if (items[i] != 0) {
            isA = false; break;
        }
    }

    return isA;
}
*/
