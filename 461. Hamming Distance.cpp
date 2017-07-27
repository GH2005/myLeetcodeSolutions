class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int xx = x ^ y; xx != 0; xx >>= 1)
            if ((xx & 1) == 1) res++;
        return res;
    }
};
