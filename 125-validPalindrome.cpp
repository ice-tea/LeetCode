class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        
        int last = size-1;
        int i=0;
        while(i<=last){
            while(i<size && !isalpha(s[i]) && !isalnum(s[i]))
                ++i;
            while(last>=0 && !isalpha(s[last]) && !isalnum(s[last]))
                --last;
            if(i<size && last>=0)
                if(toupper(s[i++]) != toupper(s[last--]))
                    return false;
        }
        return true;
    }
};
