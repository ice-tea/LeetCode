class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        k %=s;
        nums.insert(nums.begin()+s, nums.begin(),nums.begin()+s-k);
        nums.erase(nums.begin(),nums.begin()+s-k);
    }
};
