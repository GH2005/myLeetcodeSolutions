class Solution {
  static std::vector<int> st_dp;
public:
  int numSquares(int n) {
    int const prevSize = st_dp.size();
    if (n < prevSize) { return st_dp[n]; }
    
    // fill the missing elements
    int const newSize = n + 1;
    st_dp.resize(newSize, INT_MAX);
    for (int i = std::sqrt(prevSize), square = i * i; square < newSize; ++i, square = i * i) {
      st_dp[square] = 1;
    }
    for (int value = prevSize; value < newSize; ++value) {
      if (st_dp[value] != INT_MAX) { continue; }
      for (int left = 1, right = value - 1; left <= right; ++left, --right) {
        st_dp[value] = std::min(st_dp[value],  st_dp[left] + st_dp[right]);
      }
    }
    
    return st_dp[n];
  }
};

std::vector<int> Solution::st_dp(2, 1);
