class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int i = 0,j=s-1;
        int tmp;
        while(j>i){
            while(i<s && nums[i] == 0)
                ++i;
            while(j>=0 && nums[j] !=0)
                --j;
            if(j>i){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        j=s-1;
        while(j>i){
            while(i<s && nums[i] == 1)
                ++i;
            while(j>=0 && nums[j] !=1)
                --j;
            if(j>i){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
};
