class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "";
        string b = "1";
        int i = 1;
        while(i<n){
            b = say(b);
            i++;
        }
        return b;
    }
    string say(string str){
        string res="";
        int s = str.size();
        int cur = 0;
        char c = '0';
        for(int i=0;i<s;i++){
            cur = 1;
            c = str[i];
            while(i+1<s && str[i+1]==str[i]){
                cur++;
                i++;
            }
            res = res + char('0'+cur);
            res = res + char(c);
        }
        return res;
    }
};
