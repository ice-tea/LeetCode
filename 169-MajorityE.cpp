class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> tmp =nums;
        int s;
        int i;
        s=tmp.size();
        while(s>1){
            for(i=0;i<s;i=i+2){
                if(i+1<s && tmp[i]==tmp[i+1])
                    tmp.push_back(tmp[i]);
                else if(i+1==s)
                    tmp.push_back(tmp[s-1]);
            }
            tmp.erase(tmp.begin(),tmp.begin()+s);
            s=tmp.size();
        }
        return tmp[0];
    }
    /*
    int majorityElement2(vector<int>& nums) {
        //unordered_map<int, int> myMap;
        map<int, int> myMap;
        for (auto& num: nums) {
            myMap[num]++;
            if (myMap[num]>nums.size()/2)
                return num;
         }
    }
    */
};
