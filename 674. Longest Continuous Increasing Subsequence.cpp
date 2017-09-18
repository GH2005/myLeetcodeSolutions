class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int cIncreasing = 1;
        int maxCIncreasing = 1;
        for (int pos = 1; pos < len; pos++)
        {
            if (nums[pos-1] < nums[pos]) cIncreasing++;
            else 
            {
                if (maxCIncreasing < cIncreasing)
                    maxCIncreasing = cIncreasing;
                cIncreasing = 1;
            }
        }
        if (maxCIncreasing < cIncreasing)
            maxCIncreasing = cIncreasing;
        return maxCIncreasing;
    }
};
