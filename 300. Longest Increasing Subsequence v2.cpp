// idea from the editorial solutions
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size());
        auto beginIt = dp.begin(), endIt = beginIt;
        for (int num : nums) {
            auto it = std::lower_bound(beginIt, endIt, num);
            if (it == endIt) ++endIt;
            *it = num;
        }
        return endIt - beginIt;
    }
};
