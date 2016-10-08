class Solution {
public:

    inline int GetValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }

    int romanToInt(string s) {
        
        int res = 0;
        int prevValue = 1001;
        for (int i = 0; i < s.size(); i++) {
            int iValue = GetValue(s[i]);
            if (iValue > prevValue) res += (iValue - prevValue * 2);
            else res += iValue;
            prevValue = iValue;
        }
        
        return res;
        
    }
};
