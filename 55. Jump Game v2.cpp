class Solution {
public:
  bool canJump(vector<int>& nums) {
    ptrdiff_t const lastIndex = nums.size() - 1;
    if (lastIndex < 0) return false;
    for (ptrdiff_t left = 0, right = std::min(left + nums[left], lastIndex);;) {
      ptrdiff_t newRight = 0;
      for (ptrdiff_t i = left; i <= right; ++i) {
        newRight = std::max(newRight, i + nums[i]);
        if (newRight >= lastIndex) { return true; }
      }
      if (newRight <= right) { return false; }
      else {
        left  = right + 1;
        right = newRight;
      }
    }
  }
};
