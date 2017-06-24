class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (int pos = 0; pos < s.size(); pos++)
            res ^= s[pos] ^ t[pos];
        res ^= t.back();
        return res;
    }
};
