class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int half = sum / 2;
        std::vector<bool> dp(sum + 1); dp[0] = true;
        for (int num : nums) {
            for (int hashValue = sum; 0 <= hashValue; --hashValue) {
                if (dp[hashValue] == false) { continue; }
                int newHashValue = hashValue + num;
                if (newHashValue == half) { return true; }
                dp[newHashValue] = true;
            }
        }
        return false;
    }
};
