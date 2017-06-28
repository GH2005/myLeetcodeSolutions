// dp version
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        if (len == 3) return max(nums[0] + nums[2], nums[1]);
        int dp[3] = { nums[len-3] + nums[len-1], nums[len-2], nums[len-1] };
        int res = 0;
        for (int pos = 0; pos < 3; pos++) if (res < dp[pos]) res = dp[pos];
        for (int pos = len-4; 0 <= pos; pos--)
        {
            int value = nums[pos] + max(dp[1], dp[2]);
            if (res < value) res = value;
            dp[2] = dp[1], dp[1] = dp[0], dp[0] = value;
        }
        return res;
    }
};
