class Solution {
public:
    int maxProduct(vector<int>& nums) {
      ptrdiff_t const len = nums.size();
      if (len == 0) { return std::numeric_limits<int>::min(); }
      std::vector<int> dp(len, 1);
      int maxP = std::numeric_limits<int>::min();
      for (ptrdiff_t lastWinLen = 0; lastWinLen < len; ++lastWinLen) {
        ptrdiff_t const dpLen = len - lastWinLen;
        for (ptrdiff_t i = 0; i < dpLen; ++i) {
          dp[i] *= nums[i+lastWinLen];
          maxP = std::max(maxP, dp[i]);
        }
      }
      return maxP;
    }
};
