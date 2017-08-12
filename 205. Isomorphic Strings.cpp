class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapping1[128] = {}, mapping2[128] = {};
        for (int pos = 0; pos < s.size(); pos++)
        {
            int ch1 = s[pos], ch2 = t[pos];
            if (mapping1[ch1] == 0) mapping1[ch1] = ch2;
            else if (mapping1[ch1] != ch2) return false;
            if (mapping2[ch2] == 0) mapping2[ch2] = ch1;
            else if (mapping2[ch2] != ch1) return false;
        }
        return true;
    }
};
