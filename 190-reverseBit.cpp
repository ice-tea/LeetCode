class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int bit = 0;
        for(int i=0; i<32; i++)
        {
            bit = n&1;
            n = n>>1;

            result = 2*result + bit;
        }
        return result;
    }
};
