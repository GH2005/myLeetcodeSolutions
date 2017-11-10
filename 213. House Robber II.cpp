class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        if (len == 3) return *max_element(nums.begin(), nums.end());
        vector<int> dp(len);
        // first pass: rob the first house
        dp[0] = dp[1] = nums[0];
        for (int pos = 2; pos < len-1; pos++)
            dp[pos] = max(dp[pos-1], dp[pos-2] + nums[pos]);
        int firstResult = dp[len - 2];
        // second pass: do not rob the first house
        dp[0] = 0, dp[1] = nums[1];
        for (int pos = 2; pos < len-1; pos++)
            dp[pos] = max(dp[pos-1], dp[pos-2] + nums[pos]);
        int secondResult = max(dp[len-2], dp[len-3] + nums[len-1]);
        return max(firstResult, secondResult);
    }
};
