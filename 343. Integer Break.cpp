class Solution {
    int dp[59];
public:
    Solution()
    {
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int n = 4; n <= 58; n++)
        {
            int maxProduct = 1;
            for (int part1 = 1; part1 <= n/2; part1++)
                maxProduct = max(maxProduct, dp[part1] * dp[n-part1]);
            dp[n] = maxProduct;
        }
    }
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        return this->dp[n];
    }
};
