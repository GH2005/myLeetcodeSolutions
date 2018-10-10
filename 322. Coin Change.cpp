class Solution {//editorial solution
public:
    int coinChange(vector<int>& coins, int amount) {
      ptrdiff_t const len = coins.size();
      if (len == 0) return -1;
      std::vector<int> dp(amount + 1);
      dp[0] = 0;
      for (int i = 1; i <= amount; ++i) {
        int dpI = std::numeric_limits<int>::max();
        for (int denomination : coins) {
          int const prevIndex = i - denomination;
          if (prevIndex >= 0 && dp[prevIndex] >= 0) {
            dpI = std::min(dpI, dp[prevIndex] + 1);
          }
        }
        dp[i] = dpI < std::numeric_limits<int>::max() ? dpI : -1;
      }
      return dp[amount];
    }
};
