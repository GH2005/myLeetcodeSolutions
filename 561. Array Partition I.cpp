class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int pos = 0; pos < len; pos += 2)
            sum += nums[pos];
        return sum;
    }
};
