class Solution {
public:
    string minWindow(string s, string t) {
        int count[CHARSIZE] = {0};
        int required[CHARSIZE] = {0};
        
        //record the t's count
        for(int i=0;i<t.size();++i){
            needCheck.insert(t[i]-'A');
            required[t[i]-'A']++;
        }
        
        //check
        int posA = 0;
        int posB = 0;
        int minLen = INT_MAX;
        string res = "";
        for(posB=0;posB<s.size();++posB){
            count[s[posB]-'A']++;
            while(isValid(count,required)){
                if(minLen > posB-posA+1){
                    minLen = posB-posA+1;
                    res = s.substr(posA,posB-posA+1);
                    //cout<<res<<endl;
                }
                if(required[s[posA]-'A']==0)
                    posA++;
                else{
                    count[s[posA++]-'A']--;
                }
            }
        }
        return res;
    }
private:
    static const int CHARSIZE=58;
    set<int> needCheck;
    bool isValid(int* arr1, int* arr2){
        for(set<int>::iterator i=needCheck.begin(); i!=needCheck.end();++i){
            if(arr1[*i]<arr2[*i])
                return false;
        }
        return true;
    }
};
