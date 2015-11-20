class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        int bit = 0;
        for(int i=0; i<32; i++)
        {
            bit = n&1;
            n = n>>1;

            result += bit;
        }
        return result;
    }
};
