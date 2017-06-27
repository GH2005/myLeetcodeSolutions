class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        for (int mask = 1; 0 < mask; mask <<= 1)
            if (n == mask) return true;
        return false;
    }
};
