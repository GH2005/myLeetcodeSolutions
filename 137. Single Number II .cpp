// fun4LeetCode's solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x0 = 0, x1 = 0;
        for (int value : nums)
        {
            x1 ^= x0 & value;
            x0 ^= value;
            int mask = ~x0 | ~x1;
            x1 &= mask;
            x0 &= mask;
        }
        return x0;
    }
};
