class Solution {
public:
    int search(vector<int>& nums, int target) {
      ptrdiff_t left = 0, right = nums.size() - 1;
      while (left <= right) {
        ptrdiff_t const mid = left + (right - left) / 2;
        int const numLeft = nums[left], numMid1 = nums[mid], numRight = nums[right];
        if (numLeft <= numRight) {
          if (target <= numMid1) { right = mid - 1; }
          else                   { left  = mid + 1; };
        }
        else {
          int const numMid2 = nums[mid + 1];
          if (numLeft <= numMid1 && numLeft <= target && target <= numMid1) {
            right = mid;
            continue;
          }
          if (numMid2 <= numRight && numMid2 <= target && target <= numRight) {
            left = mid + 1;
            continue;
          }
          if (numLeft > numMid1) { right = mid; }
          else                   { left  = mid + 1; }
        }
      }
      return left < nums.size() && nums[left] == target ? left : -1;
    }
};
