class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int currConsecutive = 0;
        for (int value : nums)
        {
            if (value == 0) currConsecutive = 0;
            else res = max(res, ++currConsecutive);
        }
        return res;
    }
};
