class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int xx = x ^ y; xx != 0; xx &= xx-1)
            res++;
        return res;
    }
};
