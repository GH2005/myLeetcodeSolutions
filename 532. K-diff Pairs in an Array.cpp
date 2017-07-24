class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2 || k < 0) return 0;
        int left = 0, right = 1;
        int res = 0;
        sort(nums.begin(), nums.end());
        while (right < len)
        {
            if (0 < left && nums[left-1] == nums[left]) { left++; continue; }
            if (1 < right && nums[right-1] == nums[right]) { right++; continue; }
            if (left == right) right++;
            int diff = nums[right] - nums[left];
            if (diff == k) { res++; left++; right++; }
            else if (diff < k) right++;
            else left++;
        }
        return res;
    }
};
