class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int c = 32;
        while (n > 0)
        {
            c--;
            (res <<= 1) += n & 1;
            n >>= 1;
        }
        while (c > 0)
        {
            res <<= 1;
            c--;
        }
        return res;
    }
};
