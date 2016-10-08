class Solution {
public:
    char GetCh(int pos, int need) {
        if (need == 1)
            switch (pos) {
                case 3: return 'M'; break;
                case 2: return 'C'; break;
                case 1: return 'X'; break;
                case 0: return 'I'; break;
            }
        else {
            // need == 5;
            assert(pos != 3);
            switch (pos) {
                case 2: return 'D'; break;
                case 1: return 'L'; break;
                case 0: return 'V'; break;
            }
        }
    }

    string intToRoman(int num) {
        
        int digits[4];
        for (int i = 0; i < 4; i++) {
            digits[i] = num % 10;
            
            num /= 10;
        }
        
        string res;
        for (int i = 3; i >= 0; i--) {
            int thisDgt = digits[i];
            if (thisDgt == 0) continue;
            int mod5 = thisDgt % 5;
            if (mod5 <= 3) {
                if (thisDgt >= 5) res += GetCh(i, 5);
                for (int j = 0; j < mod5; j++) {
                res += GetCh(i, 1);
                }
            }
            else {
                if (thisDgt == 4) { res += GetCh(i, 1); res += GetCh(i, 5); }
                else { res += GetCh(i, 1); res += GetCh(i + 1, 1); }
            }
        }
        
        return res;
        
    }
};
