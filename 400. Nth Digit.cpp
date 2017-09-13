class Solution {
public:
    int findNthDigit(int n) {
        long long base = 1, len = 1, m = n;
        while ((m -= 9 * base * len) > 0)
            base *= 10, len += 1;
        m += 9 * base * len - 1;
        int q = m / len, r = m % len;
        int container = base + q;
        int times = len - r;
        int res = 0;
        for (int i = 0; i < times; i++)
        {
            res = container % 10;
            container /= 10;
        }
        return res;
    }
};
