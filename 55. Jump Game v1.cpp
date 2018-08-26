class Solution {
public:
    bool canJump(vector<int>& nums) {
      //I'm assuming only stepping forward is allowed
      ptrdiff_t const len = nums.size();
      if (len == 0) return false;
      std::vector<bool> dp(len, false);
      dp[len-1] = true;
      for (ptrdiff_t i = len - 2; 0 <= i; --i) {
        ptrdiff_t const localLast = std::min(i + nums[i], len - 1);
        for (ptrdiff_t j = i; j <= localLast; ++j) {
          if (dp[j]) { dp[i] = true; break; }
        }
      }
      return dp[0];
    }
};
