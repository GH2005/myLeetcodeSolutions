class Solution {
public:
    int reverse(int x) {
        
        if (x == 0) return x;
        
        bool minus = x < 0;
        if (minus) x = 0 - x;
        int cDigits = 0;
        int digits[10];
        
        do {
            digits[cDigits] = x % 10;
            cDigits ++;
        } while ((x /= 10) != 0);
        
        int res = 0;
        for (int i = cDigits - 1; i >= 0; i --) {
            res += digits[i] * pow(10, cDigits - i - 1);
            if (res < 0) {
                return 0;
            }
        }

        if (minus) res = 0 - res;
        return res;

    }
};
