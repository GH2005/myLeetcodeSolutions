class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if (0 <= nums.front() || nums.back() <= 0)
            return nums[len-1] * nums[len-2] * nums[len-3];
        // binary search for the first zero
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) left = mid + 1;
            else right = mid - 1;
        }
        // decide the response
        int res = INT_MIN;
        if (1 <= right) res = max(res, nums[0] * nums[1] * nums[len-1]);
        if (nums[left] == 0) res = max(res, 0);
        int posFirstPositive = left;
        while (nums[posFirstPositive] <= 0) posFirstPositive++;
        int positiveLen = len - posFirstPositive;
        if (3 <= positiveLen) res = max(res, nums[len-1] * nums[len-2] * nums[len-3]);
        else if (2 <= positiveLen) res = max(res, nums[len-1] * nums[len-2] * nums[0]);
        return res;
    }
};
