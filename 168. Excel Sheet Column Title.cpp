class Solution {
public:
    string convertToTitle(int n) {
        int len = 1;
        long long m = n - 1, expVal = 26;
        while ((m -= expVal) >= 0) len++, expVal *= 26;
        m += expVal;
        string res(len, 'A');
        for (int pos = len - 1; 0 <= pos; pos--)
        {
            if (m == 0) break;
            res[pos] += m % 26;
            m /= 26;
        }
        return res;
    }
};
