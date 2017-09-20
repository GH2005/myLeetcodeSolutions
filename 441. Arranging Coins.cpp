class Solution {
public:
    int arrangeCoins(int n) {
        long long m = n;
        m <<= 1;
        long long x = sqrt(m);
        if (x * (x+1) <= m && m < (x+1) * (x+2))
            return x;
        else return x-1;
    }
};
