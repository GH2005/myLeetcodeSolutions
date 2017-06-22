class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int pos = 1; pos < nums.size(); pos++)
            if (nums[pos-1] == nums[pos]) return true;
        return false;
    }
};
