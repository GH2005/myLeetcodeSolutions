class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int maxArea = 0;
    ptrdiff_t const height = matrix.size();
    if (height == 0) return maxArea;
    ptrdiff_t const width = matrix[0].size();
    
    for (ptrdiff_t y = 0; y < height; ++y) {
      for (ptrdiff_t x = 0; x < width; ++x) {
        std::vector<int> dp(width);
        ptrdiff_t rightLimit = width;
        
        for (ptrdiff_t m = y; x < rightLimit && m < height; ++m) {
          int lineAccumulation = 0;
          
          for (ptrdiff_t n = x; n < rightLimit; ++n) {
            int val = (matrix[m][n] == '1' ? 1 : 0);
            if (val == 0) { rightLimit = n; break; }
            ++lineAccumulation;
            dp[n] = dp[n] + lineAccumulation;
            maxArea = std::max(maxArea, dp[n]);
          }
        }
      }
    }
    
    return maxArea;
  }
};
