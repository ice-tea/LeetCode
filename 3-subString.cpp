#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0,j = 0;
        int max = 0;
        set<char> allc;
        while(s[i]!='\0'){
            while(s[j]!='\0'){
                if(allc.find(s[j])==allc.end()){
                    allc.insert(s[j]);
                    j++;
                }
                else{
                    if(allc.size()>max){
                        max = j-i;
                    }
                    while(s[i]!=s[j]){
                        allc.erase(s[i]);
                        i++;
                    }
                    j++;
                    break;
                }
            }
            if(s[j] == '\0'){
                if(allc.size()>max){
                    max = j-i;
                }
                break;
            }
            i++;
        }
        return max;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int size = s.size();
        int pos[128];
        memset(pos, -1, 128 * sizeof(int));
        int max = 0;
        int offset = 0;     // offset marks the new start of the substring
        for (int i=0; i < size; i++) {
            char ch = s[i];
            if (pos[ch] < offset)   // s[i] doesn't exist in substring,
            {
                pos[ch] = i; // mark s[i] with its position
                max = i+1-offset>max? i + 1 -offset:max;
            }
            else // s[i] exists in substring
            {
                offset = pos[ch] + 1;
                pos[ch] = i;
            }
        }
        return max;
    }
};

int main(){
    string str = "abcad";
    Solution s;
    int res = s.lengthOfLongestSubstring(str);
    printf("%d",res);
}


