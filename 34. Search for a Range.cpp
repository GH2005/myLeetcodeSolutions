class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        for (int times = 0; times < 2; times++) {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (target < nums[mid]) right = mid - 1;
                else if (nums[mid] < target) left = mid + 1;
                else
                    if (times == 0) right = mid - 1;
                    else left = mid + 1;
            }
            if (times == 0) { if (left < nums.size() && nums[left] == target) res[0] = left; }
            else { if (0 <= right && nums[right] == target) res[1] = right; }
        }
        return res;
    }
};
