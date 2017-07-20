class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half = nums.size() / 2;
        int res = 0;
        for (int mask = 1; mask != 0; mask <<= 1)
        {
            int c = 0;
            for (int value : nums)
                if ((value & mask) != 0) c++;
            if (half < c) res ^= mask;
        }
        return res;
    }
};
