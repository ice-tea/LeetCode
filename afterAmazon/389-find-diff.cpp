class Solution {
public:
    char findTheDifference(string s, string t) {
        int countS[26];
        int countT[26];
        for(int i=0;i<26;++i){
            countS[i]=0;
            countT[i]=0;
        }
        
        for(int i=0;i<s.length();++i){
            countS[s[i]-'a']++;
            countT[t[i]-'a']++;
        }
        countT[t[s.length()]-'a']++;
        
        for(int i=0;i<26;++i){
            if(countS[i]!=countT[i])
                return 'a'+i;
        }
        return 'a';
    }
};
