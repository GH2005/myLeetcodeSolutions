class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[right] == val) { --right; continue; }
            if (nums[left] != val) { left++; continue; }
            nums[left++] = nums[right--];
        }
        return left;
    }
};
