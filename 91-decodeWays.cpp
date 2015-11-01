class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len==0)
            return 0;
        if(len==1)
            return s[0]!='0';
        int a = (s[len-1]!='0');
        int b = 0;
        if(s[len-2]=='0')
            b = valid(s[len-2],s[len-1]);
        else
            b = a +  valid(s[len-2],s[len-1]);
        int tmp;
        for(int i=len-3;i>=0;--i){
            tmp = b;
            if(s[i] =='0')
                b = 0;
            else if(valid(s[i],s[i+1]))
                b+=a;
            a = tmp;
        }
        return b;
    }
   
    bool valid(char a,char b){
        return(a=='1'||(a=='2'&&(b-'0'<7)));
    }
};
