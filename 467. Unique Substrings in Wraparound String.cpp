class Solution {
    inline char get_next(char c) {
        // c should always be in range ['a', 'z']
        if (c == 'z') return 'a';
        else return c + 1;
    }
public:
    int findSubstringInWraproundString(string p) {
        // edge input cases
        int len = p.size();
        if (len == 0) return 0;
        if (len == 1) return 1;
        
        // dynamic programming
        int res = 0;
        bool exists[26];
        memset(exists, false, sizeof(bool)*26);
        // count len 1 substrings seperately
        for (int i = 0; i < len; i++) {// letter p[i]
            if (exists[p[i] - 'a']) continue;
            exists[p[i] - 'a'] = true;
            res ++;
        }
        // treat len-2 substrings seperately too
        memset(exists, false, sizeof(bool)*26);
        bool dpValue[20000];
        memset(dpValue, false, sizeof(bool)*len);
        for (int i = 0; i < len - 1; i++) {// substring p[i...i+1]
            // check if this substring is valid
            bool valid = p[i+1] == this->get_next(p[i]);
            // if it is valid, do not count repetitive ones
            if (valid) {
                dpValue[i] = true;
                if (!exists[p[i]-'a']) {
                    exists[p[i]-'a'] = true;
                    res ++;
                }
            }
        }
        
        // window lengh == 3, 4, 5...*len*
        for (int windowSize = 3; windowSize <= len; windowSize ++) {
            // add all valid substrings of length *windowSize*
        
            memset(exists, false, sizeof(bool)*26);
            bool thereIsOne = false; // one "two consective 'true's"
            bool theLast = false;
            for (int i = 0; i < len - (windowSize-1); i++) {
                // substring p[i..i+windowSize)
                if (dpValue[i] == true && dpValue[i+1] == true) {
                    if (theLast = true) thereIsOne = true;
                    theLast = true;
                    if (!exists[p[i]-'a']) {
                        exists[p[i]-'a'] = true;
                        res ++;
                    }
                }
                else {
                    dpValue[i] = false;
                    theLast = false;
                }
            }
            if (!thereIsOne) break;
        }
        
        // return
        return res;
    }
};
