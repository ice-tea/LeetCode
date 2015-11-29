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
/*
class NumArray {
public:
    vector<int> memo = {0};
    NumArray(vector<int> &nums) {
        int summ = 0;
        for (int n : nums) {
            summ += n;
            memo.push_back(summ);
        }
    }

    int sumRange(int i, int j) {
        return memo[j+1] - memo[i];
    }
};
*/
