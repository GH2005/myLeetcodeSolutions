class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            // add to count
            count += (n & 0x00000001);
            // move right by one bit
            n = n >> 1;
        }
        return count;
    }
};
