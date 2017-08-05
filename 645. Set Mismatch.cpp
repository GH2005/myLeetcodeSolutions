class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return {};
        int duplicate = 0, missed = 0;
        for (int pos = 0; pos < len; pos++)
        {
            while (nums[pos] != pos + 1 && nums[pos] != nums[nums[pos]-1])
                swap(nums[pos], nums[nums[pos]-1]);
        }
        for (int pos = 0; pos < len; pos++)
            if (nums[pos] != pos + 1) return { nums[pos], pos+1 };
    }
};
