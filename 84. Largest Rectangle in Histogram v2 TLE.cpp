class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    this->maxArea = 0;
    this->divide_and_conquer(0, heights.size() - 1, heights);
    return this->maxArea;
  }
private:
  void divide_and_conquer(int const left, int const right, auto const &heights) {
    if (right < left) return;
    std::vector<int> indices { left - 1 };
    for (int i = left; i <= right; ++i) {
      if (indices.size() > 1 && heights[i] < heights[indices.back()]) indices.resize(1);
      if (indices.size() < 2) indices.push_back(i);
      else if (heights[i] <= heights[indices.back()]) indices.push_back(i);
    }
    indices.push_back(right + 1);
    
    this->maxArea = std::max(this->maxArea, heights[indices[1]] * (right + 1 - left));
    
    for (int ii = 1; ii < indices.size(); ++ii) {
      this->divide_and_conquer(indices[ii - 1] + 1, indices[ii] - 1, heights);
    }
  }
private:
  int maxArea = 0;
};
