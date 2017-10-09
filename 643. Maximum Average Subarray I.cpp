class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int pos = 0;
        while (pos < k)
        {
            sum += nums[pos];
            pos++;
        }
        int res = sum;
        for (; pos < nums.size(); pos++)
        {
            sum += nums[pos] - nums[pos-k];
            if (sum > res) res = sum;
        }
        return double(res) / double(k);
    }
};
