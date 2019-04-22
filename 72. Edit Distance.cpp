// solution from https://www.youtube.com/watch?v=b6AGUjqIPsA
class Solution {
public:
  int minDistance(string word1, string word2) {
    ptrdiff_t const height = static_cast<ptrdiff_t>(word1.size() + 1);
    ptrdiff_t const width  = static_cast<ptrdiff_t>(word2.size() + 1);
    std::vector<int> dp(width);
    std::iota(dp.begin(), dp.end(), 0);
    for (ptrdiff_t i = 1; i < height; ++i) {
      int last = dp[0];
      dp[0] = i;
      for (ptrdiff_t j = 1; j < width; ++j) {
        if (word1[i-1] == word2[j-1]) {
          std::swap(last, dp[j]);
        }
        else {
          int const value = std::min({ last, dp[j-1], dp[j] }) + 1;
          last = dp[j];
          dp[j] = value;
        }
      }
    }
    return dp[width - 1];
  }
};
