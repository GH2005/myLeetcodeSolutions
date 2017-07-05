// other people's idea
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorB = 0;
        for (int value : nums) aXorB ^= value;
        int mask = aXorB & (-aXorB);
        int a = 0, b = 0;
        for (int value : nums)
        {
            if ((value & mask) == 0) a ^= value;
            else b ^= value;
        }
        return {a, b};
    }
};
