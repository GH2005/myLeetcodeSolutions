class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int len = nums.size();
        if (len <= 1) return len;
        std::multimap<int, int, std::greater<int>> dp;
        int res = 1;
        for (int i = len - 1; 0 <= i; --i) {
            auto endIt = dp.cend();
            for (auto it = dp.cbegin(); it != endIt; ++it) {
                if (nums[i] < it->second) {
                    const int thisLen = it->first + 1;
                    res = std::max(res, thisLen);
                    dp.insert(it, std::make_pair(thisLen, nums[i]));
                    goto done;
                }
            }
            dp.insert(endIt, std::make_pair(1, nums[i]));
            done:;
        }
        return res;
    }
};
