class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for (int value : nums)
        {
            sum += value;
            if (maxSum < sum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};
