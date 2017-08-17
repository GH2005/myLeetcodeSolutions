class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int mask = 1 << 15;
        while (mask != 0)
        {
            res |= mask;
            if (46340 < res || x < res * res) res ^= mask;
            else if (x == res * res) return res;
            mask >>= 1;
        }
        return res;
    }
};
