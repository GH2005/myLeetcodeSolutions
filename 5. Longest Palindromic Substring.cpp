class Solution {
public:
    string longestPalindrome(string s) {
        
        // preprocess.
        string mstr;
        mstr.resize(s.size() * 2 + 1 + 2, 'a');
        mstr[0] = '$';
        int iMstr = 1;
        for (int i = 0; i < s.size(); i++) {
            mstr[iMstr] = '#';
            mstr[iMstr + 1] = s[i];
            iMstr += 2;
        }
        mstr[mstr.size() - 2] = '#';
        mstr[mstr.size() - 1] = '^';
        
        // process.
        int id = 0, mx = 0;
        int* p = new int[mstr.size()];
        for (int i = 1; i < mstr.size() - 1; i++) {
            p[i] = i < mx ? (p[2 * id - i] > (mx - i) ? (mx - i) : p[2 * id - i]) : 1;
            while (mstr[i + p[i]] == mstr[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        
        // get the response.
        int mxLen = 0;
        int iMx = 0;
        for (int i = 1; i <= mstr.size() - 2; i++) {
            if (p[i] > mxLen) {
                mxLen = p[i];
                iMx = i;
            }
        }
        string res = "";
        res.reserve(2 * mxLen - 1);
        for (int i = iMx - mxLen + 1; i < iMx + mxLen - 1; i+=2) {
            res += mstr[i + 1];
        }
        
        // clean.
        delete[] p;
        
        // return
        return res;
        
    }
};
