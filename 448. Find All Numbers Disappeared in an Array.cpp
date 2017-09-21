class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int pos = 0; pos < nums.size(); pos++)
        while (nums[pos] != pos+1 && nums[nums[pos] - 1] != nums[pos])
            swap(nums[pos], nums[nums[pos] - 1]);
        vector<int> res;
        for (int pos = 0; pos < nums.size(); pos++)
            if (nums[pos] != pos+1) res.push_back(pos+1);
        return res;
    }
};
