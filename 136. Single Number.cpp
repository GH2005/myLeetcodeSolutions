class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int value : nums) res ^= value;
        return res;
    }
};
