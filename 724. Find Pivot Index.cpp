class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int v : nums) sum += v;
        int leftSum = 0, rightSum = sum;
        for (int pos = 0; pos < nums.size(); pos++)
        {
            rightSum -= nums[pos];
            if (leftSum == rightSum) return pos;
            leftSum += nums[pos];
        }
        return -1;
    }
};
