class Solution {
public:
    string reverseStr(string s, int k) {
        if (k <= 1) return s;
        int len = s.size(), pos = 0;
        for (int pos = 0; pos < len; pos += 2 * k)
        {
            int end = min(len, pos + k);
            reverse(s.begin() + pos, s.begin() + end);
        }
        return s;
    }
};
