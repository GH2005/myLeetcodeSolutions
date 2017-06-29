class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || 0x40000000 % num != 0) return false;
        double dpw = log2(num);
        int ipw = dpw + 0.5;
        return ipw % 2 == 0;
    }
};
