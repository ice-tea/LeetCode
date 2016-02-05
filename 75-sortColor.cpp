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


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int pos0=0;
        int pos2=len-1;
        
        int i=0;
        while(i<len && i<=pos2){
            if(nums[i] == 0){
                if(i==pos0){
                    ++i;
                    continue;
                }
                else{
                    nums[i]=nums[pos0];
                    nums[pos0++] = 0;
                }
            }
            else if(nums[i] == 2){
                if(i==pos2){
                    ++i;
                    continue;
                }
                else{
                    nums[i]=nums[pos2];
                    nums[pos2--] = 2;
                }
            }
            else{
                ++i;
            }
        }
        
        return;
    }
};
