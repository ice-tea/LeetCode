class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string tmp;
        int l,r;
        //ostringstream convert1;
        //ostringstream convert2;
        for(int i=0;i<nums.size();i++){
            l = nums[i];
            while(i<nums.size()-1 && nums[i+1]==nums[i]+1)
                ++i;
            r = nums[i];
            //convert1 << l;
            //convert2 << r;
            //(l==r)?res.push_back(convert1.str()):res.push_back( convert1.str() +"->"+ convert2.str());
            //convert1.str("");
            //convert2.str("");
            (l==r)?res.push_back(to_string(l)):res.push_back( to_string(l) +"->"+ to_string(r));
        }
        return res;
    }
};
