class Solution {
public:
    int myAtoi(string str) {
        
        int cDigits = 0;
        int digits[10];
        bool minus = false;
        bool overflow = false;
        int i = 0;
        while (str[i] == ' ') i++;
        
        // sign.
        if (str[i] == '-') { minus = true; i++; }
        else if (str[i] == '+') { minus = false; i++; }
        
        // digits.
        while (str[i] >= '0' && str[i] <= '9') {
            if (cDigits == 10) { overflow = true; break; }
            digits[cDigits] = str[i] - '0';
            cDigits ++;
            i++;
        }
        
        // compute res.
        if (overflow) return minus ? INT_MIN : INT_MAX;
        
        int res = 0;
        for (int j = 0; j < cDigits; j++) {
            res += digits[j] * pow(10, cDigits - j - 1);
            if (res < 0) return minus ? INT_MIN : INT_MAX;
        }
        
        return minus ? 0 - res : res;
        
    }
};
