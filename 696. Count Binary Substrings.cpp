class Solution {
public:
    int countBinarySubstrings(string s) {
        int len = s.size();
        if (len < 2) return 0;
        int res = 0;
        int start = 0, currPos = 1, base = s[0] - '0';
        int counts[2] = {}; counts[base] = 1;
        while (start < len - 1)
        {
            while (currPos < len)
            {
                int curr = s[currPos] - '0';
                if (curr == base && counts[!base] == 0)
                {
                    counts[base]++;
                    currPos++;
                }
                else if (curr == base) break;
                else if ((++currPos, res++, ++counts[!base])
                    == counts[base]) break;
            }
            if (currPos == len) break;
            else
            {
                start = currPos - counts[!base];
                base = !base;
                counts[!base] = 0;
            }
        }
        return res;
    }
};
