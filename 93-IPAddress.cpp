class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> indexes;
        Search(s,res,indexes,0);
        return res;
    }
    void Search(string s, vector<string>& res, vector<int>& indexes, int pos){
        if(indexes.size()==4){
            if(pos == s.size()){
                string ipAdress;
                string each = s.substr(0,indexes[0]+1);
                
                ipAdress = each;
                if(!isValid(each))
                    return;
                each = s.substr(indexes[0]+1,indexes[1]-indexes[0]);
                if(!isValid(each))
                    return;
                ipAdress = ipAdress + "." + each;
                each = s.substr(indexes[1]+1,indexes[2]-indexes[1]);
                if(!isValid(each))
                    return;
                ipAdress = ipAdress + "." + each;
                each = s.substr(indexes[2]+1);
                if(!isValid(each))
                    return;
                ipAdress = ipAdress + "." + each;
                //cout<<ipAdress;
                res.push_back(ipAdress);
            }
            return;
        }
        if(indexes.size()>4){
            return;
        }
        for(int i=pos;i<pos+3 && i<s.size() ;i++){
            indexes.push_back(i);
            Search(s,res,indexes,i+1);
            indexes.pop_back();
        }
    }
    bool isValid(string each){
        if(each[0]=='0' && each.size()>1)
            return false;
        if(each.size()==3){
            if(each[0]>='3')
                return false;
            if(each[0] == '2' && each[1]>='6')
                return false;
            if(each[0] == '2' && each[1]=='5' && each[2]>='6')
                return false;
        }
        return true;
    }
};
