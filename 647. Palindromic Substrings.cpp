class Solution {
public:
    int countSubstrings(string s)
    {
        const int len = s.size();
        if (len <= 1) return len;
        // stuffing
        string stuffed; stuffed.reserve(2*len + 3);
        stuffed.push_back('^');
        for (char c : s)
            stuffed.insert(stuffed.end(), {'#', c});
        stuffed.insert(stuffed.end(), {'#', '$'});
        // manacher's algorithm
        int pivot = -1, rb = -1;
        int cPalin = 0;
        vector<int> dp(stuffed.size(), 1);
        for (int pos = 0; pos < stuffed.size(); pos++)
        {
            int symmPos = 2*pivot - pos;
            if (pos < rb && dp[symmPos] < rb + 1 - pos)
            {
                dp[pos] = dp[symmPos];
                cPalin += dp[pos] / 2;
                continue;
            }
            int right = rb, left = 2*pos - right;
            if (rb < pos) left = pos, right = pos;
            while (stuffed[left] == stuffed[right])
            {
                dp[pos] = right + 1 - pos;
                left--, right++;
            }
            int rb2 = pos + dp[pos] - 1;
            if (rb < rb2) rb = rb2, pivot = pos;
            cPalin += dp[pos] / 2;
        }
        return cPalin;
    }
};
