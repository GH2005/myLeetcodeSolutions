class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negDividend = dividend < 0 ? true : false;
        bool negDivisor = divisor < 0 ? true : false;
        if (dividend == 0) return 0;
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long absDividend = llabs(dividend);
        long long absDivisor = llabs(divisor);
        long long absQuotient = 0;
        // adding to absQuotient
        while (absDivisor <= absDividend) {
            long long qb = absDivisor;
            long long q = 1;
            while (qb <= absDividend) {
                qb <<= 1;
                q <<= 1;
            }
            absQuotient += (q >> 1);
            absDividend -= (qb >> 1);
        }
        
        
        if (negDividend ^ negDivisor) return -absQuotient;
        else return absQuotient;
    }
};
