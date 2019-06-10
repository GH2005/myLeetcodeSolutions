// Solution from KusKus87.
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int const len = heights.size();
    
    std::stack<int> stk;
    std::vector<int> nextSmallers(len, len);
    for (int i = 0; i < len; ++i) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        nextSmallers[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    
    stk = std::stack<int>();
    std::vector<int> prevSmallers(len, -1);
    for (int i = len - 1; 0 <= i; --i) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        prevSmallers[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    
    int maxArea = 0;
    for (int i = 0; i < len; ++i) {
      maxArea = std::max(maxArea, heights[i] * (nextSmallers[i] - prevSmallers[i] - 1));
    }
    
    return maxArea;
  }
};
