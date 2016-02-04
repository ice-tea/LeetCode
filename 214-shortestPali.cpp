class Solution {
public:
    string shortestPalindrome(string s) {
        string sR = s;
        reverse(sR.begin(),sR.end());
        
        int len = s.length();
        
        int pos = 0;
        while(pos<len){
            //check middle pos -0.5
            if(s.substr(0,len-pos) == sR.substr(pos)){
                break;
            }
            pos++;
        }
        string res = sR.substr(0,pos);
        cout<<res;
        return res+s;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        int minAdd = len*2;

        int pos = 0;
        bool valid = false;
        while(pos<len/2){
            //check middle pos -0.5
            valid = true;
            for(int i=1;i<=pos;i++){
                if(s[pos-i]!=s[pos+i-1]){
                    valid = false;
                    break;
                }
            }
            if(valid)
                minAdd = min(minAdd, 2*(len-pos));
            //check middle pos
            valid = true;
            for(int i=1;i<=pos;i++){
                if(s[pos-i]!=s[pos+i]){
                    valid = false;
                    break;
                }
            }
            if(valid)
                minAdd = min(minAdd, 2*(len-pos)-1);
            pos++;
        }
        cout<<minAdd<<endl;
        string res = s.substr(len-minAdd+len);
        reverse(res.begin(),res.end());
        res += s;
        return res;
    }
};
