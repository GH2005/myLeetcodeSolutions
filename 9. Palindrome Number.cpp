class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) return false;
        if (x == 0) return true;
        
        int digits[10];
        int cDigits = 0;
        while (x > 0) {
            digits[cDigits] = x % 10;
            cDigits++;
            x /= 10;
        }
        
        for (int i = 0, j = cDigits - 1; i++, j--; i < j) {
            if (digits[i] != digits[j]) return false;
        }
        
        return true;
        
    }
};
