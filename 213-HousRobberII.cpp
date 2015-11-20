class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s<1)
            return 0;
        int t = nums[0];
        nums.erase(nums.begin(),nums.begin()+1);
        int t1 = rob2(nums);
        int t2 = 0;
        if(nums.size()>2){
            nums.erase(nums.begin(),nums.begin()+1);
            nums.pop_back();
            t2 = rob2(nums);
        }
        return max(t1,t+t2);
        
    }
    int rob2(vector<int>& nums) {
        int s = nums.size();
        if(s==0)
            return 0;
        int a = 0;
        int b = nums[0];
        int tmp = 0;
        for(int i=1;i<s;i++){
            tmp = max(b,a+nums[i]);
            a = b;
            b = tmp;
        }
        return b;
    }
};
