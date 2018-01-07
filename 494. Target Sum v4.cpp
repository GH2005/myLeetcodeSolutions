class Solution {
    int dp[2][2001];
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (1000 < S) return 0;
        std::memset(dp, '\0', 4002 * sizeof(int));
        dp[0][1000 + nums[0]]++;
        dp[0][1000 - nums[0]]++;
        size_t dpIndicator = 1;
        for (size_t pos = 1; pos < nums.size(); pos++)
        {
            int num = nums[pos];
            for (int offsetVal = 0; offsetVal < 2001; offsetVal++)
            {
                int count = dp[!dpIndicator][offsetVal];
                if (count == 0) continue;
                dp[dpIndicator][offsetVal + num] += count;
                dp[dpIndicator][offsetVal - num] += count;
            }
            dpIndicator = !dpIndicator;
            std::memset(dp[dpIndicator], '\0', 2001 * sizeof(int));
        }
        return dp[!dpIndicator][1000+S];
    }
};
