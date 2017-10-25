class Solution {
public:
    bool hasAlternatingBits(int n) {
        for (int last = n & 1, m = n >> 1; m != 0; last = !last, m >>= 1)
            if (last == (m & 1)) return false;
        return true;
    }
};
