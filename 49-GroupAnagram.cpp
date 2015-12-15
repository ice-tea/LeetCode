class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> MyMap;
        vector<string> tmp;
        
        string tmpS;
        int j = 0;
        for(int i=0;i<strs.size();++i){
            tmpS = strs[i];
            sort(tmpS.begin(),tmpS.end());
            if(MyMap.find(tmpS)!=MyMap.end()){
                for(j=0; j<res[MyMap[tmpS]].size();++j){
                    if(res[MyMap[tmpS]][j] > strs[i])
                        break;
                }
                res[MyMap[tmpS]].insert(res[MyMap[tmpS]].begin()+j,strs[i]);
            }
            else{
                MyMap[tmpS] = res.size();;
                tmp.clear();
                tmp.push_back(strs[i]);
                res.push_back(tmp);
            }
        }
        
        if(res.size()==0){
            tmp.clear();
            tmp.push_back("");
            res.push_back(tmp);
        }
        return res;
    }
    
};
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> tmp;
        bool found = false;
        int index = 0;
        for(int i=0;i<strs.size();++i){
            index = 0;
            tmp.clear();
            found = false;
            while(!found && index<res.size()){
                if(isAnagram(strs[i],res[index][0])){
                    found = true;
                    res[index].push_back(strs[i]);
                }
                index++;
            }
            if(found)
                continue;
            tmp.push_back(strs[i]);
            res.push_back(tmp);
        }
        if(res.size()==0){
            tmp.push_back("");
            res.push_back(tmp);
        }
        return res;
    }
    bool isAnagram(string s1, string s2) {
		if (s1 == "")
			return s2=="";
		if (s2 == "")
		    return s1=="";
		
		int len = s1.size();
		if (len != s2.size())
			return false;

		int* letters = new int[26];

		for (int i = 0; i < len; i++) {
			letters[s1[i]-'a']++;
			letters[s2[i]-'a']--;
		}

		for (int i = 0; i < 26; i++) {
			if (letters[i] != 0) {
				return false;
			}
		}
		return true;
	}
    bool areAnagram(char *str1, char *str2)
    {
        // Create 2 count arrays and initialize all values as 0
        int count1[NO_OF_CHARS] = {0};
        int count2[NO_OF_CHARS] = {0};
        int i;
 
        // For each character in input strings, increment count in
        // the corresponding count array
        for (i = 0; str1[i] && str2[i];  i++)
        {
            count1[str1[i]]++;
            count2[str2[i]]++;
        }
 
        // If both strings are of different length. Removing this
        // condition will make the program fail for strings like
        // "aaca" and "aca"
        if (str1[i] || str2[i])
        return false;
 
        // Compare count arrays
        for (i = 0; i < NO_OF_CHARS; i++)
            if (count1[i] != count2[i])
                return false;
 
        return true;
    }
};
*/
