class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int mask = 1; mask != 0; mask <<= 1)
        {
            int cOnes = 0;
            for (int pos = 0; pos < nums.size(); pos++)
            {
                bool isZero = (nums[pos] & mask) == 0;
                res += isZero ? cOnes : pos - cOnes;
                cOnes += !isZero;
            }
        }
        return res;
    }
};
