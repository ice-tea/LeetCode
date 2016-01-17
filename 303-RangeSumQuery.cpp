class NumArray {
public:
    int*arr;
    NumArray(vector<int> &nums) {
        arr = new int[nums.size()];
        copy(nums.begin(), nums.end(), arr);
    }

    int sumRange(int i, int j) {
        int res = 0;
        for(int pos = i;pos<=j;pos++){
            res += arr[pos];
        }
        return res;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
