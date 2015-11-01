class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.end());
        int i=0,j=0;
        int tmp = 0;
        while(i<m && j<n){
            if(nums1[i+tmp] <= nums2[j]){
                ++i;
            }
            else{
                nums1.insert(nums1.begin()+i+tmp++,nums2[j++]);
            }
        }
        while(j<n){
            nums1.push_back(nums2[j++]);
        }
        //return nums1;
    }
};
