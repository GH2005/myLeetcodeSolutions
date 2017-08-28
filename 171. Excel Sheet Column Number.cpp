class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int order = 1;
        for (int pos = s.size() - 1; 0 <= pos; pos--, order *= 26)
            res += (s[pos] - 'A' + 1) * order;
        return res;
    }
};
