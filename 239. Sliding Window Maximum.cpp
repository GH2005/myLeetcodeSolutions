// zhaotianzju's solution
class Solution {
  void editUseWind(std::deque<ptrdiff_t> &dq, int const i, std::vector<int> const &nums) const noexcept {
    while (!dq.empty() && nums[dq.back()] <= nums[i]) { dq.pop_back(); }
    dq.push_back(i);
  }
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::deque<ptrdiff_t> usefulWindow;
    for (ptrdiff_t i = 0; i < k - 1; ++i) {
      this->editUseWind(usefulWindow, i, nums);
    }
    std::vector<int> res;
    for (ptrdiff_t i = k - 1; i < nums.size(); ++i) {
      if (i - k == usefulWindow.front()) { usefulWindow.pop_front(); }
      this->editUseWind(usefulWindow, i, nums);
      res.push_back(nums[usefulWindow.front()]);
    }
    return res;
  }
};
