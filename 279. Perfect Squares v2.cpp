class Solution {
public:
  int numSquares(int n) {
    static std::vector<int> st_dp{0, 1};
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
      for (int i = 1, square = 1; square <= value; ++i, square = i * i) {
        st_dp[value] = std::min(st_dp[value],  st_dp[value - square] + 1);
      }
    }
    
    return st_dp[n];
  }
};
