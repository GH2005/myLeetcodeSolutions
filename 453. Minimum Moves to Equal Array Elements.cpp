class Solution {
public:
    int minMoves(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int v : nums)
            res += v - smallest;
        return res;
    }
};
