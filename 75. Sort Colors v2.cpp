class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1, mid = 0;
        while (mid <= right) {
            if (mid < left) { mid++; continue; }
            if (nums[mid] == 0) swap(nums[mid], nums[left++]);
            else if (nums[mid] == 2) swap(nums[mid], nums[right--]);
            else mid++;
        }
    }
};
