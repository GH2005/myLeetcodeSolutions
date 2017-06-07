class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int left = 0, right = len - 1;
        while (left < len && sorted[left] == nums[left]) left++;
        while (left <= right && sorted[right] == nums[right]) right--;
        return right - left + 1;
    }
};
