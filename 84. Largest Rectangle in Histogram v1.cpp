class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    std::unordered_set<int> const uniqueHeights{heights.begin(), heights.end()};
    
    int maxAreaSoFar = 0;
    for (int const height: uniqueHeights) {
      int area = 0;
      for (int const actualHeight: heights) {
        if (height <= actualHeight) {
          area += height;
        }
        else {
          maxAreaSoFar = std::max(maxAreaSoFar, area);
          area = 0;
        }
      }
      maxAreaSoFar = std::max(maxAreaSoFar, area);
    }
    return maxAreaSoFar;
  }
};
